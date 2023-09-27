#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 1e5+5;
vector<int> adj[maxn];
int dp[maxn], res = 0;

void dfs(int u){
    if(adj[u].empty()){
        dp[u] = 0;
        return;
    }
    for(int v : adj[u]) {
        if(dp[v] == -1) dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
        res = max(res, dp[u]);
    }
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(dp[i] == -1) dfs(i);
    }
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
