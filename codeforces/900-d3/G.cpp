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
#define int ll

const int maxn = 2e5 + 5, LG = 21;
const int mxl = 31;

int n;
int a[maxn];
vector<int> adj[maxn];

int up[maxn][LG], st[maxn][LG], val[maxn], t = 1;
int tin[maxn], tout[maxn], dep[maxn];
int fst[maxn][mxl];
int N, CLG;

const int neutral = 0;
int merge(int l, int r) { return l | r; }

void build(int u, int p = -1, int d = 0) {
    dep[u] = d;
    tin[u] = t++;
    for (int i = 0; i < CLG; i++) {
        up[u][i + 1] = up[up[u][i]][i];
        st[u][i + 1] = merge(st[u][i], st[up[u][i]][i]);
    }
    for (int v : adj[u]) {
        if (v != p) {
            for (int i = 0; i < mxl; i++) {
                fst[v][i] = fst[u][i];
            }
            for (int i = 0; i < mxl; i++) {
                if (val[u] & (1 << i)) fst[v][i] = u;
            }
            up[v][0] = u, st[v][0] = val[u];
            build(v, u, d + 1);
        }
    }
    tout[u] = t++;
}

void build(int root, int N2, int *v) {
    N = N2;
    for (int i = 0; i < N; i++) val[i] = tin[i] = tout[i] = dep[i] = neutral;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < mxl; j++) {
            fst[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < CLG; j++) {
            up[i][j] = st[i][j] = neutral;
        }
    }
    t = 1;
    for (int i = 0; i < N; i++) val[i] = v[i];
    up[root][0] = root;
    st[root][0] = val[root];
    build(root);
}

bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int query2(int u, int v, bool include_lca) {
    if (ancestor(u, v)) return include_lca ? val[u] : neutral;
    int ans = val[u];
    for (int i = CLG; i >= 0; i--) {
        if (!ancestor(up[u][i], v)) {
            ans = merge(ans, st[u][i]);
            u = up[u][i];
        }
    }
    return include_lca ? merge(ans, st[u][0]) : ans;
}

int query(int u, int v) {
    if (u == v) return val[u];
    return merge(query2(u, v, 1), query2(v, u, 0));
}

int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;
    for (int i = CLG; i >= 0; i--) {
        if (!ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int dis(int u, int v) {
    if (ancestor(u, v)) return dep[v] - dep[u];
    if (ancestor(v, u)) return dep[u] - dep[v];
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int kth(int u, int k) {
    for (int i = 0; i < CLG; i++) {
        if (k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

int ppc(int u) {
    return __builtin_popcount(u);
}

void solve() {
    cin >> n;
    CLG = ceil(log2(n));

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    build(0, n, a);

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        
        int LCA = lca(u, v);

        vector<int> nodes;
        nodes.eb(u);
        nodes.eb(v);
        nodes.eb(LCA);

        for (int i = 0; i < mxl; i++) {
            if (fst[u][i] != -1 && ancestor(LCA, fst[u][i])) nodes.eb(fst[u][i]);
            if (fst[v][i] != -1 && ancestor(LCA, fst[v][i])) nodes.eb(fst[v][i]);
        }


        int best = 0;
        for (auto nodo : nodes) {
            int L = query(u, nodo);
            int R = query(v, nodo);
            int now = ppc(L) + ppc(R);
            best = max(best, now);
        }
        cout << best << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(fst, -1, sizeof (fst));
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        for (int i = 0; i < n; i++) adj[i].clear();
        for (int i = 0; i < n; i++) a[i] = 0;
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
