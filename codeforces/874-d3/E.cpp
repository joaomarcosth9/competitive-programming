#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 2e5 + 5;
vector<int> adj[maxn];
bool vis[maxn];
int minn = 0;
int maxx = 0;
int cycle;

void dfs(int u, int first, int nu = 1){
    vis[u] = true;
    for(int v : adj[u]) {
        if(v == first && nu > 2){
            cycle++;
            return;
        }
        if(!vis[v]) dfs(v, first, nu+1);
    }
}

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i]--;
        adj[i].emplace_back(v[i]);
        adj[v[i]].emplace_back(i);
    }
    debug("oi");
    for(int i = 0; i < n; i++) if(!vis[i]) {
        maxx++;
        dfs(i, i);
    }
    minn = maxx;
    int t = maxx - cycle;
    minn = cycle + min(1, t);
    // ou eh tripa ou eh ciclo
    // se ciclo -> ngm liga
    // se tripa->duas pontas ligam

    cout << minn << " " << maxx << '\n';
    for(int i = 0; i < n; i++){
        adj[i].clear();
        vis[i] = false;
    }
    minn = maxx = cycle = 0;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
