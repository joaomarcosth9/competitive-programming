#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

typedef pair<int,int> ii;
const int maxn = 2e5 + 5;
vector<ii> adj[maxn];

int res = 1;

void dfs(int u = 0, int p = -1, int id = 0, int cres = 1){
    int em = INT_MAX;
    for(auto [v, i] : adj[u]) if (v != p) {
        em = min(em, i);
    }
    if(em < id){
        cres += 1;
        res = max(res, cres);
    }
    for(auto [v, i] : adj[u]) if (v != p) {
        dfs(v, u, i, cres);
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    dfs();
    cout << res << '\n';

    for(int i = 0; i < n; i++){
        adj[i].clear();
    }

    res = 1;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
