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
    struct node {
    };
    node merge(node a, node b) {
        return {};
    }

    int n;
    vector<ll> t;

    void build(int u, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[u] = v[l];
        } else {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid, v);
            build(u << 1 | 1, mid + 1, r, v);
            t[u] = merge(t[u << 1], t[u << 1 | 1]);
        }
    }

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n << 2, neutral);
    }

    void build(const vector<ll> &v) { // pra construir com vector
        n = int(v.size());
        t.assign(n << 2, neutral);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }

    ll query(int u, int l, int r, int L, int R) {
        if (l > R || r < L) {
            return neutral;
        }
        if (l >= L && r <= R) {
            return t[u];
        }
        int mid = (l + r) >> 1;
        ll ql = query(u << 1, l, mid, L, R);
        ll qr = query(u << 1 | 1, mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int u, int l, int r, int i, ll x) {
        if (l == r) {
            t[u] += x; // soma
            // t[u] = x; // substitui
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
    void update(int i, ll x) { update(1, 0, n - 1, i, x); }
};

struct HLD {
    int n, t;
    vector<vector<int>> adj;
    vector<int> sz, pos, par, head;
    bool e = 0; // flag pra dizer se eh de aresta ou nao
    SegTree ds; // pode usar qualquer estrutura de dados aqui

    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int &v : adj[u]) {
            if (v != p) {
                dfs_sz(v, u);
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
        sz = pos = par = head = vector<int>(n);
        dfs_sz(u);
        t = 0;
        par[u] = u;
        head[u] = u;
        dfs_hld(u);
    }

    void build(int root, vector<ll> v, vector<vector<int>> adj2) {
        // usar esse build pra iniciar com valores nos nodos
        n = (int)adj2.size();
        adj = adj2;
        build_hld(root);
        vector<ll> aux(n);
        for (int i = 0; i < (int)v.size(); i++) {
            aux[pos[i]] = v[i];
        }
        ds.build(aux);
    }
    void build(int root, vector<vector<int>> adj2) {
        // esse build eh para iniciar vazia
        build(root, vector<ll>(adj2.size(), ds.neutral), adj2);
    }
    void build(int root, vector<tuple<int, int, ll>> edges) {
        // usar esse build se os pesos estiverem nas arestas
        n = (int)edges.size() + 1;
        adj = vector<vector<int>>(n);
        for (auto [u, v, w] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        build_hld(root);
        e = 1;
        vector<ll> aux(n, ds.neutral);
        for (auto [u, v, w] : edges) {
            if (pos[u] > pos[v]) {
                swap(u, v);
            }
            aux[pos[v]] = w;
        }
        ds.build(aux);
    }

    ll query(int u, int v) {
        if (e && u == v) {
            return ds.neutral;
        }
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        if (head[u] == head[v]) {
            return ds.query(pos[u] + e, pos[v]);
        } else {
            ll qv = ds.query(pos[head[v]], pos[v]);
            ll qu = query(u, par[head[v]]);
            return ds.merge(qu, qv);
        }
    }
    ll query_subtree(int u) {
        if (e && sz[u] == 1) {
            return ds.neutral;
        }
        return ds.query(pos[u] + e, pos[u] + sz[u] - 1);
    }

    void update(int u, int v, ll k, bool replace = false) {
        if (e && u == v) {
            return;
        }
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        if (head[u] == head[v]) {
            ds.update(pos[u] + e, pos[v], k, replace);
        } else {
            ds.update(pos[head[v]], pos[v], k, replace);
            update(u, par[head[v]], k, replace);
        }
    }
    void update_subtree(int u, ll k, bool replace = false) {
        if (e && sz[u] == 1) {
            return;
        }
        ds.update(pos[u] + e, pos[u] + sz[u] - 1, k, replace);
    }

    int lca(int u, int v) {
        if (pos[u] > pos[v]) {
            swap(u, v);
        }
        return (head[u] == head[v] ? u : lca(u, par[head[v]]));
    }
} hld;

const int N = 1e5 + 5;
int n, q, a[N];
vector<int> adj[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < q; i++) {
        int u, v, uu, vv, k;
        cin >> u >> v >> uu >> vv >> k;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
