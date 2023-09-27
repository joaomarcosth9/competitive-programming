#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int maxn = 205;
vector<int> adj[maxn];

int nodo = -1;

void dfs(int u, int d = 0, int p = -1){
    if(d == 3){
        nodo = p;
        return;
    }
    for(int v : adj[u]) if(v != p) {
        dfs(v, d+1, u);
    }
}

int x, y;

void dfs2(int u = nodo, int d = 0, int p = -1){
    if(d == 1){
        x++;
    } else if(d == 2){
        y++;
    }
    for(int v : adj[u]) if(v != p) {
        dfs2(v, d+1, u);
    }
}

void solve(){
    int n, m; cin >> n >> m;
    x = y = nodo = 0;
    for(int i = 0; i < n; i++) adj[i].clear();
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 1){
            dfs(i);
            break;
        }
    }
    debug(nodo);
    dfs2();
    debug(x, y);
    y /= x;
    cout << x << " " << y << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
