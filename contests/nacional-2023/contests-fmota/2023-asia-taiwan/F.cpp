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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

typedef pair<int, int> ii;
const int maxn = 2e5 + 5;
int n, m;
bool vis[maxn];
int dp[maxn], dep[maxn];
vector<int> adj[maxn];
vector<ii> bridges;

void dfs_dp(int u, int p = -1, int d = 0) {
    dp[u] = 0, dep[u] = d, vis[u] = 1;
    for (auto v : adj[u]) {
        if (v != p) {
            if (vis[v]) {
                if (dep[v] < dep[u]) dp[v]--, dp[u]++;
            } else {
                dfs_dp(v, u, d + 1);
                dp[u] += dp[v];
            }
        }
    }
    if (dp[u] == 0 && p != -1) { // edge {u, p} eh uma ponte
        bridges.emplace_back(u, p);
    }
}

void find_bridges() {
    memset(vis, 0, n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs_dp(i);
        }
    }
}

// Edge Biconnected Components (requer todo codigo acima)

int ebcc[maxn], ncc = 0;
vector<int> adjbcc[maxn];

void dfs_ebcc(int u, int p, int cc) {
    vis[u] = 1;
    if (dp[u] == 0 && p != -1) {
        cc = ++ncc;
    }
    ebcc[u] = cc;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs_ebcc(v, u, cc);
        }
    }
}

void build_ebcc_graph() {
    find_bridges();
    memset(vis, 0, n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs_ebcc(i, -1, ncc);
            ++ncc;
        }
    }
    // Opcao 2 - constroi o grafo condensado passando so pelas pontes
    for (auto [u, v] : bridges) {
        adjbcc[ebcc[u]].emplace_back(ebcc[v]);
        adjbcc[ebcc[v]].emplace_back(ebcc[u]);
    }
}

namespace seg {
    const int MAX = 2e5 + 5;
    const ll NEUTRAL = 0; // merge(a, neutral) = a
    ll merge(ll a, ll b) { return a + b; }
    int sz; // size of the array
    ll tree[4 * MAX], lazy[4 * MAX];
    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }
    void push(int n, int esq, int dir) {
        if (lazy[n] == -1) return;
        tree[n] = lazy[n] * (dir - esq + 1);
        if (esq != dir) {
            lazy[le(n)] = lazy[n];
            lazy[ri(n)] = lazy[n];
        }
        lazy[n] = -1;
    }
    void build(vector<int>& v, int n, int esq, int dir) {
        if (esq == dir) tree[n] = v[esq];
        else {
            int mid = (esq + dir) / 2;
            build(v, le(n), esq, mid);
            build(v, ri(n), mid + 1, dir);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void build(vector<int> v) {
        sz = v.size();
        memset(lazy, -1, sizeof(lazy));
        build(v, 0, 0, sz - 1);
    }
    ll query(int l, int r, int n = 0, int esq = 0, int dir = sz - 1) {
        push(n, esq, dir);
        if (esq > r || dir < l) return NEUTRAL;
        if (l <= esq && dir <= r) return tree[n];
        int mid = (esq + dir) / 2;
        return merge(query(l, r, le(n), esq, mid), query(l, r, ri(n), mid + 1, dir));
    }
    void update(int l, int r, ll v, int n = 0, int esq = 0, int dir = sz - 1) {
        push(n, esq, dir);
        if (esq > r || dir < l) return;
        if (l <= esq && dir <= r) {
            lazy[n] += v;
            push(n, esq, dir);
        } else {
            int mid = (esq + dir) / 2;
            update(l, r, v, le(n), esq, mid);
            update(l, r, v, ri(n), mid + 1, dir);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
} // namespace seg

namespace hld {
    const int MAX = 2e5 + 5;
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX];
    bool e = 0;
    ll merge(ll a, ll b) { return max(a, b); } // how to merge paths
    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (int &v : adjbcc[u])
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adjbcc[u][0]] || adjbcc[u][0] == p) swap(v, adjbcc[u][0]);
            }
    }
    void dfs_hld(int u, int p = -1) {
        pos[u] = t++;
        for (int v : adjbcc[u])
            if (v != p) {
                pai[v] = u;
                head[v] = (v == adjbcc[u][0] ? head[u] : v);
                dfs_hld(v, u);
            }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build(int root, vector<i3> &edges) { // use this if weighted edges
        build(root);
        e = 1;
        vector<int> aux(edges.size() + 1);
        for (auto [u, v, w] : edges) {
            if (pos[u] > pos[v]) swap(u, v);
            aux[pos[v]] = w;
        }
        seg::build(aux);
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) return seg::query(pos[u] + e, pos[v]);
        else {
            ll qv = seg::query(pos[head[v]], pos[v]);
            ll qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    void update(int u, int v, ll k) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) seg::update(pos[u] + e, pos[v], k);
        else {
            seg::update(pos[head[v]], pos[v], k);
            update(u, pai[head[v]], k);
        }
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return (head[u] == head[v] ? u : lca(u, pai[head[v]]));
    }
    ll query_subtree(int u) { return seg::query(pos[u], pos[u] + sz[u] - 1); }
} // namespace hld

struct Dsu {
    vector<int> p;
    vector<ll> sz;
    Dsu(int N) : p(N), sz(N, 1) {
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int find(int a) { return a == p[a] ? a : p[a] = find(p[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = b;
        sz[a] = 0;
        return true;
    }
};

bool vis2[maxn];
void dfs(int u, int s, Dsu& d) {
    d.unite(u, s);
    vis2[u] = 1;
    for (int v : adj[u]) if (!vis2[v]) {
        dfs(v, s, d);
    }
}

void solve() {
    cin >> n >> m;
    int q; cin >> q;
    vector<ii> edges;
    set<ii> del;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        edges.eb(u, v);
    }
    vector<ii> queries(q);
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        del.emplace(u, v);
    }
    for (int i = 0; i < m; i++) {
        if (del.count(edges[i])) continue;
        auto [u, v] = edges[i];
        adj[u].eb(v);
        adj[v].eb(u);
    }

    Dsu dsu(n);
    dfs(0, 0, dsu);

    build_ebcc_graph();

    vector<i3> ed;
    int curr = 0;

    for (int u = 0; u < ncc; u++) {
        debug(u, adjbcc[u]);
        for (auto v : adjbcc[u]) {
            curr += 1;
            ed.eb(min(u, v), max(u, v), 1);
        }
    }

    curr /= 2;

    sort(all(ed));
    ed.erase(unique(all(ed)), end(ed));

    hld::build(0, ed);

    reverse(all(queries));
    vector<int> res;

    res.eb(curr);
    debug(curr);
    for (int i = 0; i < q; i++) {
        auto [u, v] = queries[i];
        if (dsu.find(u) != dsu.find(v)) {
            u = ebcc[u], v = ebcc[v];
            if (hld::pos[u] > hld::pos[v]) swap(u, v);
            hld::update(u, hld::pai[u], 1);
            curr += 1;
        } else {
            u = ebcc[u], v = ebcc[v];
            int old = hld::query(u, v);
            hld::update(u, v, 0);
            curr -= old;
        }
        dsu.unite(u, v);
        if (i < q - 1) res.eb(curr);
    }

    reverse(all(res));
    for (auto u : res) cout << u << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
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
