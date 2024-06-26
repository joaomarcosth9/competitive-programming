#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct SegTree {
    int merge(int a, int b) { return a + b; }
    const int neutral = 0;

    int n;
    vector<int> t;

    void build(int u, int l, int r, const vector<int> &v) {
        if (l == r) {
            t[u] = v[l];
        } else {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid, v);
            build(u << 1 | 1, mid + 1, r, v);
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }

    void build(const vector<int> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n << 2, neutral);
        build(1, 0, n - 1, v);
    }

    int query(int u, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        int ql = query(u << 1, l, mid, L, R);
        int qr = query(u << 1 | 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int u, int l, int r, int i, int x) {
        if (l == r) {
            t[u] = x; // substitui
        } else {
            int mid = (l + r) >> 1;
            if (i <= mid) {
                update(u << 1, l, mid, i, x);
            } else {
                update(u << 1 | 1, mid + 1, r, i, x);
            }
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }
    void update(int i, int x) { update(1, 0, n - 1, i, x); }
};

struct MinSegTree {
    using T = pair<int, int>;
    T merge(T a, T b) { return max(a, b); }
    const T neutral = {INT_MIN, -1};

    int n;
    vector<T> t;

    void build(int u, int l, int r, const vector<T> &v) {
        if (l == r) {
            t[u] = v[l];
        } else {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid, v);
            build(u << 1 | 1, mid + 1, r, v);
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }

    void build(const vector<T> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n << 2, neutral);
        build(1, 0, n - 1, v);
    }

    T query(int u, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        T ql = query(u << 1, l, mid, L, R);
        T qr = query(u << 1 | 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int u, int l, int r, int i, T x) {
        if (l == r) {
            t[u] = x; // substitui
        } else {
            int mid = (l + r) >> 1;
            if (i <= mid) {
                update(u << 1, l, mid, i, x);
            } else {
                update(u << 1 | 1, mid + 1, r, i, x);
            }
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }
    void update(int i, T x) { update(1, 0, n - 1, i, x); }
};

const int N = 3e5 + 5;
int n, q;
vector<int> adj[N];
int c[N], sz[N], pos[N], par[N], head[N], dep[N];
set<int> black_child[N];
set<pair<int, int>> black_depths;
int cnt;

struct HLD {
    int t;
    bool e = 0; // flag pra dizer se eh de aresta ou nao
    SegTree ds;
    MinSegTree ds2;

    void dfs_sz(int u, int p = -1, int d = 0) {
        sz[u] = 1;
        dep[u] = d;
        for (int &v : adj[u]) {
            if (v != p) {
                dfs_sz(v, u, d + 1);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) {
                    swap(v, adj[u][0]);
                }
            }
        }
    }
    void dfs_hld(int u, int p = -1) {
        pos[u] = t++;
        for (int v : adj[u]) {
            if (v != p) {
                par[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
        }
    }
    void build_hld(int u) {
        dfs_sz(u);
        t = 0;
        par[u] = u;
        head[u] = u;
        dfs_hld(u);
    }

    void build(int root) {
        // usar esse build pra iniciar com valores nos nodos
        build_hld(root);
        vector<int> aux(n);
        vector<pair<int, int>> aux2(n);
        for (int i = 0; i < n; i++) {
            aux[pos[i]] = c[i];
            if (c[i]) aux2[pos[i]] = {dep[i], i};
            else aux2[pos[i]] = {INT_MIN, -1};
        }
        ds.build(aux);
        ds2.build(aux2);
    }

    int query(int u, int v) {
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        if (head[u] == head[v]) {
            return ds.query(pos[u], pos[v]);
        } else {
            int qv = ds.query(pos[head[v]], pos[v]);
            int qu = query(u, par[head[v]]);
            return ds.merge(qu, qv);
        }
    }

    int query_subtree(int u) {
        return ds2.query(pos[u] + e, pos[u] + sz[u] - 1).second;
    }

    void update(int u, int k) {
        ds.update(pos[u], k);
        if (k == 1) {
            ds2.update(pos[u], {dep[u], u});
        } else {
            ds2.update(pos[u], {INT_MIN, -1});
        }
    }

    int lca(int u, int v) {
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        return (head[u] == head[v] ? u : lca(u, par[head[v]]));
    }

    int dis(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

} hld;

void solve() {
    cin >> n >> q;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        cnt += c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    hld.build(0);

    for (int i = 0; i < n; i++) {
        if (c[i] == 1) {
            black_depths.insert({dep[i], i});
            if (par[i] != i) {
                black_child[par[i]].insert(i);
            }
        }
    }
    
    while (q--) {
        int u; cin >> u;
        u--;

        if (c[u] == 0) {
            c[u] = 1;
            cnt++;

            black_depths.insert({dep[u], u});

            if (par[u] != u) {
                black_child[par[u]].insert(u);
            }

            hld.update(u, 1);

        } else {

            c[u] = 0;
            cnt--;

            black_depths.erase({dep[u], u});

            if (par[u] != u) {
                black_child[par[u]].erase(u);
            }

            hld.update(u, 0);
        }

        if (cnt == 0) {
            cout << "No" << endl;
            continue;
        } else if (cnt == 1) {
            cout << "Yes" << endl;
            continue;
        }

        // tenho que pegar o nodo preto mais alto
        auto [d, v] = *black_depths.begin();

        if (black_child[v].empty()) {
            cout << "No" << endl;
        } else {
            if (black_child[v].size() == 1) {

                auto v2 = *black_child[v].begin();
                auto lowest = hld.query_subtree(v2);

                int qnt = hld.query(v, lowest);

                if (cnt == qnt && qnt == hld.dis(v, lowest) + 1) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }

            } else {

                auto it = black_child[v].begin();
                auto v1 = *it;
                auto lowest = hld.query_subtree(v1);

                it++;
                auto v2 = *it;
                auto lowest2 = hld.query_subtree(v2);

                int qnt1 = hld.query(v, lowest);
                int qnt2 = hld.query(v, lowest2);

                int qnt = qnt1 + qnt2 - 1;

                int qnt_nodes = hld.dis(lowest, lowest2) + 1;

                if (cnt == qnt && qnt == qnt_nodes) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }

    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            black_child[i].clear();
            c[i] = pos[i] = par[i] = head[i] = dep[i] = 0;
        }
        cnt = 0;
        black_depths.clear();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
