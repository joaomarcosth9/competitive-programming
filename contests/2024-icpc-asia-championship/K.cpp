#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAXN = 1e7;

struct SegTree {
    vector<int> t;

    const int MAX = 1e5 + 5;

    vector<int> Lc, Rc, roots;

    inline int newnode() {
        t.push_back(0);
        Lc.push_back(-1);
        Rc.push_back(-1);
        return (int)t.size() - 1;
    }

    inline int le(int u) {
        if (Lc[u] == -1) {
            Lc[u] = newnode();
        }
        return Lc[u];
    }

    inline int ri(int u) {
        if (Rc[u] == -1) {
            Rc[u] = newnode();
        }
        return Rc[u];
    }

    SegTree() {
        roots.push_back(newnode());
    }

    void update(int u, int old, int l, int r, int i, int x) {
        if (l == r) {
            t[u] = x;
        } else {
            int mid = l + (r - l) / 2;
            if (i <= mid) {
                Rc[u] = ri(old);
                update(le(u), le(old), l, mid, i, x);
            } else {
                Lc[u] = le(old);
                update(ri(u), ri(old), mid + 1, r, i, x);
            }
            t[u] = t[le(u)] + t[ri(u)];
        }
    }

    int update(int i, int x, int root = -1) {
        if (root == -1) root = roots.back();
        int new_root = newnode();
        update(new_root, root, 0, MAX, i, x);
        roots.push_back(new_root);
        return (int)roots.back();
    }

    pair<int, int> kth(int u, int exclude, int l, int r, int k) {
        if (l == r) {
            return {l, k};
        } else {
            int mid = l + (r - l) / 2;
            if (t[le(u)] - t[le(exclude)] >= k) {
                return kth(le(u), le(exclude), l, mid, k);
            } else {
                return kth(ri(u), ri(exclude), mid + 1, r, k - (t[le(u)] - t[le(exclude)]));
            }
        }
    }

    pair<int, int> kth(int k, int root = -1, int exclude_root = -1) {
        if (root == -1) root = roots.back();
        if (exclude_root == -1) exclude_root = 0;
        return kth(root, exclude_root, 0, MAX, k);
    }

    int copy_root(int root) {
        roots.push_back(newnode());
        Lc[roots.back()] = Lc[root];
        Rc[roots.back()] = Rc[root];
        return roots.back();
    }

};

const int N = 1e5 + 5;
int n, q;
vector<int> adj[N];
int par[N], sz[N], roots[N], roots2[N], tin[N], tout[N], up[N][20];
SegTree seg, seg2;
int clk = 0;

void dfs_sz(int u) {
    sz[u] = 1;
    tin[u] = clk++;
    for (int i = 0; i < 19; i++) {
        up[u][i + 1] = up[up[u][i]][i];
    }
    for (int &v : adj[u]) {
        up[v][0] = u;
        dfs_sz(v);
        sz[u] += sz[v];
        if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
    }
    tout[u] = clk++;
}

int root = 0;

void build_seg(int u) {
    seg.update(u, sz[u]);
    roots[u] = seg.roots.back();
    for (int v : adj[u]) {
        seg.update(u, sz[u] - sz[v]);
        build_seg(v);
    }
    seg.update(u, 0);
}

void dfs_get(int u, int p) {
    roots2[p] = seg2.update(u, 1, roots2[p]);
    for (int v : adj[u]) {
        dfs_get(v, p);
    }
}

void build_seg2(int u) {
    for (int v : adj[u]) {
        build_seg2(v);
    }
    if (adj[u].empty()) {
        roots2[u] = seg2.update(u, 1, 0);
    } else {
        roots2[u] = seg2.copy_root(roots2[adj[u][0]]);
        roots2[u] = seg2.update(u, 1, roots2[u]);
        for (int v : adj[u]) {
            if (v != adj[u][0]) {
                dfs_get(v, u);
            }
        }
    }
}

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;
    for (int i = 19; i >= 0; i--) {
        if (anc(up[u][i], v)) continue;
        u = up[u][i];
    }
    return up[u][0];
}

int almost_lca(int u, int l) {
    if (!anc(l, u)) assert(false);
    debug("almost", u, l);
    debug(up[u]);
    for (int i = 19; i >= 0; i--) {
        if (anc(up[u][i], l)) continue;
        u = up[u][i];
    }
    debug(u);
    return u;
}

void solve() {
    cin >> n >> q;

    seg.t.reserve(MAXN);
    seg.Lc.reserve(MAXN);
    seg.Rc.reserve(MAXN);
    seg.roots.reserve(MAXN);
    seg2.t.reserve(MAXN);
    seg2.Lc.reserve(MAXN);
    seg2.Rc.reserve(MAXN);
    seg2.roots.reserve(MAXN);

    int r = -1;
    for (int i = 0; i < n; i++) {
        cin >> par[i];
        par[i]--;
        if (par[i] >= 0) adj[par[i]].push_back(i);
        else par[i] = i, r = i;
    }

    up[r][0] = r;
    dfs_sz(r);

    build_seg(r);

    build_seg2(r);

    while (q--) {
        ll k; cin >> k;
        k--;
        int x = (int)(k / n), y = -1;
        k %= n;
        auto [l, nk] = seg.kth((int)k + 1, roots[x]);
        k = nk;
        debug(x, l);
        if (x == l) {
            auto [yy, _] = seg2.kth((int)k, roots2[x]);
            y = yy;
        } else {
            int l2 = almost_lca(x, l);
            debug(x, l, l2, k);
            auto [yy, _] = seg2.kth((int)k, roots2[l], roots2[l2]);
            y = yy;
        }

        ll res = (ll)x * n * n + (ll)l * n + y;
        cout << res << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
