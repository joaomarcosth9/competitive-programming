#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define int ll
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

struct BinaryLifting {
    vector<vector<int>> adj, up;
    vector<int> tin, tout;
    int N, LG, t;

    const int neutral = 0;
    int merge(int l, int r) { return l + r; }

    void dfs(int u, int p = -1) {
        tin[u] = t++;
        for (int i = 0; i < LG - 1; i++) up[u][i + 1] = up[up[u][i]][i];
        for (int v : adj[u]) if (v != p) {
            up[v][0] = u;
            dfs(v, u);
        }
        tout[u] = t++;
    }

    void build(int root, vector<vector<int>> adj2) {
        t = 0;
        N = size(adj2);
        LG = 32 - __builtin_clz(N);
        adj = adj2;
        tin = tout = vector<int>(N);
        up = vector (N, vector<int>(LG));
        up[root][0] = root;
        dfs(root);
    }

    bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

    int lca(int u, int v) {
        if (ancestor(u, v)) return u;
        if (ancestor(v, u)) return v;
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }

    int lca2(int u, int v) {
        assert(ancestor(v, u));
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) u = up[u][i];
        }
        return u;
    }

    int kth(int u, int k) {
        for (int i = 0; i < LG; i++) {
            if (k & (1 << i)) u = up[u][i];
        }
        return u;
    }

} bl;

const int maxn = 4e5 + 5, INF = 3e6;

int n, q;
vector<int> adj[maxn];
vector<ll> tour;

int tin[maxn], tout[maxn], dep[maxn], res[maxn];
int T = -1;

void pre_dfs(int u = 0, int p = -1, int d = 0) {
    dep[u] = d;
    tin[u] = ++T;
    tour.eb(u);

    for (auto v : adj[u]) if (v != p) {
        pre_dfs(v, u, d + 1);
    }

    tout[u] = T;
}

bool anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

namespace seg {
    const int MAX = maxn;

    ll seg[4 * MAX], lazy[4 * MAX];
    int n;
    vector<ll> v;

    ll build(int p = 1, int l = 0, int r = n - 1) {
        lazy[p] = 0;
        if (l == r) return seg[p] = v[l];
        int m = (l + r) / 2;
        return seg[p] = max(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
    }
    void build(int n2, vector<ll> v2) {
        n = n2, v = v2;
        build();
    }
    void prop(int p, int l, int r) {
        seg[p] += lazy[p];
        if (l != r) lazy[2 * p] += lazy[p], lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }
    ll query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l and r <= b) return seg[p];
        if (b < l or r < a) return INT_MIN;
        int m = (l + r) / 2;
        return max(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
    }
    ll update(int a, int b, int x, int p = 1, int l = 0, int r = n - 1) {
        prop(p, l, r);
        if (a <= l and r <= b) {
            lazy[p] += x;
            prop(p, l, r);
            return seg[p];
        }
        if (b < l or r < a) return seg[p];
        int m = (l + r) / 2;
        return seg[p] = max(update(a, b, x, 2 * p, l, m), update(a, b, x, 2 * p + 1, m + 1, r));
    }
}

vector<pair<int, vector<int>>> Q[maxn];

void dfs(int u = 0, int p = -1) {

    for (auto [id, blocked] : Q[u]) {
        for (auto v : blocked) {
            if (anc(v, u)) {
                int x = bl.lca2(u, v);
                seg::update(0, n - 1, -INF);
                seg::update(tin[x], tout[x], INF);
            } else {
                seg::update(tin[v], tout[v], -INF);
            }
        }

        res[id] = seg::query(0, n - 1);

        for (auto v : blocked) {
            if (anc(v, u)) {
                int x = bl.lca2(u, v);
                seg::update(0, n - 1, INF);
                seg::update(tin[x], tout[x], -INF);
            } else {
                seg::update(tin[v], tout[v], INF);
            }
        }
    }

    for (int v : adj[u]) if (v != p) {
        seg::update(0, n - 1, 1);
        seg::update(tin[v], tout[v], -2);
        dfs(v, u);
        seg::update(0, n - 1, -1);
        seg::update(tin[v], tout[v], +2);
    }

}

void solve() {
    cin >> n >> q;

    vector<vector<int>> adj2(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
        adj2[u].eb(v);
        adj2[v].eb(u);
    }

    pre_dfs();
    bl.build(0, adj2);

    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        x--;
        vector<int> now;

        for (int j = 0; j < k; j++) {
            int u; cin >> u;
            u--;
            now.eb(u);
        }
        Q[x].eb(i, now);
    }

    vector<ll> base = tour;

    for (int i = 0; i < n; i++) {
        base[i] = dep[base[i]];
    }

    seg::build(n, base);

    dfs();

    for (int i = 0; i < q; i++) cout << res[i] << endl;

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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
