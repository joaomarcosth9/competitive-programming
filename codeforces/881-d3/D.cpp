#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
long long dp[maxn];

void dfs(int u = 0, int p = -1){
    if(u != 0 && adj[u].size() == 1){
        dp[u] = 1;
    }
    for(int v : adj[u]) if(v != p) {
        dfs(v, u);
        dp[u] += dp[v];
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs();
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v; u--, v--;
        cout << dp[u] * dp[v] << '\n';
    }
    for(int i = 0; i < n; i++){
        adj[i].clear();
        dp[i] = 0;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
