#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

int n;
long long k, c;
const int maxn = 2e5+5;
vector<int> adj[maxn];
int dep[maxn], tin[maxn], tout[maxn];
int par[maxn][30];
int n1, n2;
long long res = 0, t = 0;

void dfs(int u, int p = -1, int d = 0){
    dep[u] = d;
    tin[u] = t++;
    if(p != -1) {
        par[u][0] = p;
        for(int i = 0; i < 29; i++){
            par[u][i+1] = par[par[u][i]][i];
        }
    }
    for(int v : adj[u]) if(v != p) {
        dfs(v, u, d+1);
    }
    tout[u] = t++;
}

bool isAncestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(isAncestor(u, v)) return u;
    if(isAncestor(v, u)) return v;
    for(int i = 29; i >= 0; i--){
        if(!isAncestor(par[u][i], v)){
            u = par[u][i];
        }
    }
    return par[u][0];
}

long long dis(int u, int v){
    int _lca = lca(u, v);
    return dep[u] - dep[_lca] + dep[v] - dep[_lca];
}

void dfs2(int u, int p = -1){
    long long cost = max(dis(u, n1), dis(u, n2)) * k - dep[u] * c;
    res = max(res, cost);
    for(int v : adj[u]) if(v != p) {
        dfs2(v, u);
    }
}

pair<int,int> dfs3(int u, int p = -1, int d = 0){
    int dis = d;
    int nodo = u;
    for(int v : adj[u]) if(v != p) {
        auto [_nodo, _dis] = dfs3(v, u, d+1);
        if(_dis > dis){
            dis = _dis;
            nodo = _nodo;
        }
    }
    return {nodo, dis};
}

void solve(){
    cin >> n >> k >> c;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(0);
    n1 = dfs3(0).first;
    n2 = dfs3(n1).first;
    dfs2(0);
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) {
            solve();
            for(int i = 0; i <= n; i++) adj[i].clear();
            t = res = 0;
        }
    } else solve();
    return 0;
}
