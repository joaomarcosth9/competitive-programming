#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int,int> ii;
const int maxn = 2e5 + 5;
int dp[maxn];
vector<ii> adj[maxn];
vector<int> res;
bool dr = false;

void dfs(int u = 0, int p = -1){
    if(dr) return;
    dp[u] = 1;
    debug(u);
    for(auto [v, i] : adj[u]) if (v != p) {
        dfs(v, u);
        dp[u] += dp[v];
        if(dp[v] == 0){
            res.emplace_back(i);
        }
    }
    if(dp[u] > 3){
        dr = true;
        return;
    }
    if(dp[u] == 3){
        dp[u] = 0;
    }
}

void solve(){
    int n; cin >> n;
    vector<ii> edges;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.emplace_back(u, v);
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    for(int i = 0; i < n; i++){
        debug(i, adj[i]);
    }
    dfs();
    if(dp[0] != 0) dr = true;
    if(dr){
        cout << -1 << '\n';
    } else {
        cout << res.size() << '\n';
        for(auto i : res){
            cout << i+1 << " ";
        }
        cout << '\n';
    }
    for(int i = 0; i < n; i++){
        adj[i].clear();
        dp[i] = 0x00000ll;
    }
    dr = false;
    res.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
