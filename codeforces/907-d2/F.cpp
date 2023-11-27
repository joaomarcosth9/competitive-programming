#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int MAX = 500500;
vector<int> adj[MAX];
const int maxn = MAX;

namespace Seg {
    ll seg[4 * maxn], lazy[4 * maxn];
    int n;
    bool change[4 * maxn];
    int T = 0;

    ll build(int u = 1, int l = 1, int r = n) {
        if (l == r) return seg[u] = 0;
        int mid = (l + r) / 2;
        return seg[u] = build(u << 1, l, mid) + build(u << 1 | 1, mid + 1, r);
    }

    void buildseg(int n2) {
        n = n2;
        fill(seg, seg + (4 * n + 100), 0);
        fill(lazy, lazy + (4 * n + 100), 0);
        fill(change, change + (4 * n + 100), 0);
        debug("segn", n);
        build();
    }

    void push(int u, int L, int R) {
        if (L < R) for (int i = 0; i < 2; i++) {
            int v = (u << 1) + i;
            if (change[u]) {
                lazy[v] = lazy[u];
                change[v] = 1;
            } else {
                lazy[v] += lazy[u];
            }
        }
        if (change[u]) seg[u] = 0;
        seg[u] += lazy[u] * (R - L + 1);
        lazy[u] = change[u] = 0;
    }

    ll query(int l, int r, int u = 1, int L = 1, int R = n) {
        push(u, L, R);
        if (r < L || l > R) return 0;
        if (L >= l && R <= r) return seg[u];
        int mid = (L + R) / 2;
        return query(l, r, u << 1, L, mid) + query(l, r, u << 1 | 1, mid + 1, R);
    }

    void update(int l, int r, int x, bool rep, int u = 1, int L = 1, int R = n) {
        push(u, L, R);
        if (r < L || l > R) return;
        if (L >= l && R <= r) {
            lazy[u] = x;
            change[u] = rep;
            push(u, L, R);
            return;
        }
        int mid = (L + R) / 2;
        update(l, r, x, rep, u << 1, L, mid);
        update(l, r, x, rep, u << 1 | 1, mid + 1, R);
        seg[u] = seg[u << 1] + seg[u << 1 | 1];

    } 
}

struct HLD {
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX];
    bool e;
    ll merge(ll a, ll b) { return a + b; } // how to merge paths
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int &v : adj[u]) {
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
            }
        }
    }
    void dfs_hld(int u, int p = -1) {
        pos[u] = t++;
        for (int v : adj[u])
            if (v != p) {
                pai[v] = u;
                head[v] = (v == adj[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
    }
    void build(int root) {
        dfs_sz(root);
        e = 0;
        t = 1;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build(int root, vector<ll> v) {
        build(root);
        vector<ll> aux(v.size());
        Seg::buildseg(size(aux));
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v])
            return Seg::query(pos[u] + e, pos[v]);
        else {
            ll qv = Seg::query(pos[head[v]], pos[v]);
            ll qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    void update(int u, int v, ll k, bool rep) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) {
            Seg::update(pos[u] + e, pos[v], k, rep);
        } else {
            Seg::update(pos[head[v]], pos[v], k, rep);
            update(u, pai[head[v]], k, rep);
        }
    }
    void update_subtree(int u, ll x, bool rep) {
        Seg::update(pos[u], pos[u] + sz[u] - 1, x, rep);
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return (head[u] == head[v] ? u : lca(u, pai[head[v]]));
    }
    ll query_subtree(int u) { return Seg::query(pos[u], pos[u] + sz[u] - 1); }
} hld;

void solve() {
    int n = 1;
    int next = 2;
    int q; cin >> q;
    vector<i3> queries;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u; cin >> u;
            adj[u].eb(next);
            adj[next].eb(u);
            queries.eb(1, u, next);
            n++;
            next++;
        } else {
            int u; ll x; cin >> u >> x;
            queries.eb(2, u, x);
        }
    }

    vector<ll> aux(n);
    debug(size(aux));
    hld.build(1, aux);

    for (auto bla : queries) {
        debug(bla);
        int t = get<0>(bla);
        if (t == 1) {
            auto [_, u, v] = bla;
            hld.update_subtree(v, 0, 1);
        } else {
            auto [_, u, x] = bla;
            hld.update_subtree(u, x, 0);
            debug(hld.query(u, u));
        }
    }

    for (int i = 1; i <= n; i++) cout << hld.query(i, i) << " ";
    cout << endl;

    for (int i = 0; i <= n; i++) adj[i].clear();
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
