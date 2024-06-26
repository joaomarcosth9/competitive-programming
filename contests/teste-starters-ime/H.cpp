#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e5 + 5, MOD = 998244353;
int n, m, dp[N];
bool vis[N];
vector<int> adj[N], toposort;

void topo(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            topo(v);
        }
    }
    toposort.push_back(u);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topo(i);
        }
    }
    for (int u : toposort) {
        dp[u] = 1;
        for (int v : adj[u]) {
            dp[u] += dp[v];
            dp[u] %= MOD;
        }
    }
    cout << dp[0] - 1 << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}