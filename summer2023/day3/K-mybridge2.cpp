#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 0;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 4e5;
int n, m;
bool vis[maxn];
int ncc = 2, dp[maxn], pa[maxn], dep[maxn], ebcc[maxn];
vector<ii> adj[maxn], adjbcc[maxn];
vector<i3> bridges;
bool nodeHas[maxn];

void dfs_dp(int u, int p = -1, int d = 0) {
    dep[u] = d;
    pa[u] = p;
    vis[u] = true;
    for (auto [v, a] : adj[u])
        if (v != p) {
            if (vis[v]) {
                if (dep[v] < dep[u]) dp[v]--, dp[u]++;
            } else {
                dfs_dp(v, u, d + 1);
                dp[u] += dp[v];
            }
        }
}

void dfs_bcc(int u, int p = -1, int cc = 1) {
    vis[u] = true;
    if (dp[u] == 0 && p != -1) {
        cc = ncc++;
    }
    ebcc[u] = cc;
    for (auto [v, a] : adj[u])
        if (!vis[v]) {
            dfs_bcc(v, u, cc);
        }
}

void find_bridges() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs_dp(i);
    }
    for (int i = 1; i <= n; i++) {
        if (dp[i] == 0 && pa[i] != -1) {
            int u = i, v = pa[i];
            // edge uv eh uma ponte
            /* bridges.emplace_back(u, v); */
        }
    }
}

void build_ebcc_graph() { // PRECISA RODAR find_bridges() ANTES
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs_bcc(i);
    }
    // Opcao 1 - constroi o grafo condensado passando por todas as edges
    for (int u = 1; u <= n; u++) {
        for (auto [v, a] : adj[u]) {
            if (ebcc[u] != ebcc[v]) {
                adjbcc[ebcc[u]].emplace_back(ebcc[v], a);
            } else {
                if (a) nodeHas[ebcc[u]] = 1;
            }
        }
    }
    // Opcao 2 - constroi o grafo condensado passando so pelas pontes
    /* for(auto [u,v] : bridges){ */
    /*     adjbcc[ebcc[u]].emplace_back(ebcc[v]); */
    /*     adjbcc[ebcc[v]].emplace_back(ebcc[u]); */
    /* } */
}

bool res = false;

void dfs(int u, int d, int p = -1, bool found = false) {
    if (nodeHas[u]) found = true;
    if (u == d) {
        res = found;
        return;
    }
    for (auto [v, a] : adjbcc[u])
        if (v != p) {
            bool _found = found;
            if (a) _found = true;
            dfs(v, d, u, _found);
        }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int a;
        cin >> a;
        adj[u].push_back(ii(v, a));
        adj[v].push_back(ii(u, a));
    }
    int u, d;
    cin >> u >> d;
    find_bridges();
    build_ebcc_graph();
    u = ebcc[u], d = ebcc[d];
    dfs(u, d);
    cout << (res ? "YES" : "NO") << endl;
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
