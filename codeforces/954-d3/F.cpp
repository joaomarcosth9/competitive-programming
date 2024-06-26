#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e5 + 5;
int n, m, timer;
vector<int> adj[N];
int tin[N], low[N];

void dfs(int u, int p = -1) {
    low[u] = tin[u] = ++timer;
    for (int v : adj[u]) {
        if (tin[v] != 0 && v != p) {
            low[u] = min(low[u], tin[v]);
        } else if (v != p) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if (p != -1 && low[u] == tin[u]) {
        // edge (p, u) is a bridge
    }
}

void find_bridges() {
    timer = 0;
    for (int i = 0; i < n; i++) tin[i] = low[i] = 0;
    for (int i = 0; i < n; i++)
        if (tin[i] == 0) dfs(i);
}

// Edge Biconnected Components (requer todo o código acima)

int ebcc[N], ncc = 0;
vector<int> adjbcc[N];
int cnt_nodes[N];

void dfs_ebcc(int u, int p, int cc) {
    if (p != -1 && low[u] == tin[u]) cc = ++ncc;
    ebcc[u] = cc;
    cnt_nodes[cc]++;
    for (int v : adj[u])
        if (ebcc[v] == -1) dfs_ebcc(v, u, cc);
}

void build_ebcc_graph() {
    find_bridges();
    ncc = 0;
    for (int i = 0; i < n; i++) ebcc[i] = -1;
    for (int i = 0; i < n; i++) { // should follow the same order of find_bridges dfs
        if (ebcc[i] == -1) {
            dfs_ebcc(i, -1, ncc);
            ++ncc;
        }
    }
    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) {
            if (ebcc[u] != ebcc[v]) {
                adjbcc[ebcc[u]].emplace_back(ebcc[v]);
            }
        }
    }
}

ll res = LLONG_MAX;
ll sub[N];

void dfs_sz(int u, int p = -1) {
    sub[u] = cnt_nodes[u];
    for (int v : adjbcc[u]) {
        if (v != p) {
            dfs_sz(v, u);
            sub[u] += sub[v];
        }
    }
    if (p != -1) {
        debug(u, sub[u]);
        res = max(res, (n - sub[u]) * sub[u]);
    }
}

void solve() {
    cin >> n >> m;
    res = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v); 
        adj[v].push_back(u); 
    }
    build_ebcc_graph();
    for (int i = 0; i < ncc; i++) {
        if (sub[i] == 0) {
            dfs_sz(i);
        }
    }
    cout << (ll)(n) * (n - 1) / 2 - res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            adjbcc[i].clear();
            cnt_nodes[i] = sub[i] = tin[i] = low[i] = 0;
        }
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}