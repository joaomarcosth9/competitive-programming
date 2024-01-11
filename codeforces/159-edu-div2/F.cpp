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

struct basis {
    int b[20];
    int t[20];
    basis() { memset(b, 0, sizeof b); memset(t, -1, sizeof t); }
    basis(int u, int y) { memset(b, 0, sizeof b); memset(t, -1, sizeof t); insert(u, y); }
    int find(int x, int d) {
        for (int i = 0; i < 20; i++) if (x & (1 << i)) {
            if (t[i] < d) return 0;
            x ^= b[i];
        }
        return 1;
    }
    void insert(int x, int d) {
        for (int i = 0; i < 20; i++) if (x & (1 << i)) {
            if (d > t[i]) {
                swap(b[i], x);
                swap(t[i], d);
            }
            x ^= b[i];
        }
    }
};

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

    void build(int root, vector<vector<int>>& adj2) {
        t = 1;
        N = size(adj2);
        LG = 31 - __builtin_clz(N);
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

    int kth(int u, int k) {
        for (int i = 0; i < LG; i++) {
            if (k & (1 << i)) u = up[u][i];
        }
        return u;
    }

} bl;

const int maxn = 2e5 + 5;

int a[maxn], dep[maxn];
basis b[maxn];
vector<int> adj[maxn];

void dfs(int u, int p = -1, int d = 0) {
    dep[u] = d;
    b[u].insert(a[u], d);
    for (int v : adj[u]) if (v != p) {
        b[v] = b[u];
        dfs(v, u, d + 1);
    }
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> adj2(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
        adj2[u].eb(v);
        adj2[v].eb(u);
    }

    bl.build(0, adj2);

    dfs(0);

    int q; cin >> q;

    while (q--) {
        int u, v, k; cin >> u >> v >> k;
        u--; v--;
        auto l = bl.lca(u, v);
        auto bu = b[u];
        for (int i = 0; i < 20; i++) {
            if (b[v].t[i] >= dep[l]) {
                bu.insert(b[v].b[i], b[v].t[i]);
            }
        }
        cout << (bu.find(k, dep[l]) ? "Yes" : "No") << endl;
    }
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
