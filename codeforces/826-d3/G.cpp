#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> house(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<vector<int>> lives(n);
    
    for(int i = 1; i < n; i++) {
        int h; cin >> h; h--;
        house[i] = h;
        lives[h].emplace_back(i);
    }

    int k; cin >> k;

    vector<bool> nocar(n);
    for(int i = 0; i < k; i++){
        int f; cin >> f; f--;
        nocar[f] = 1;
    }

    vector<vector<int>> masks(n);

    queue<int> q;
    q.emplace(0);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
