#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 1e5 + 5;
vector<int> adj[maxn];
int n, res[maxn];
set<int> curr;
set<int> st[maxn];

void dfs(int u, int p, int d, vector<int>& dis){
    dis[u] = d;
    for(int v : adj[u]) if(v != p) {
        dfs(v, u, d + 1, dis);
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> d1(n), d2(n);
    dfs(0, -1, 0, d1);
    int n1 = max_element(begin(d1), end(d1)) - begin(d1);
    dfs(n1, -1, 0, d1);
    int n2 = max_element(begin(d1), end(d1)) - begin(d1);
    dfs(n2, -1, 0, d2);
    int diam = *(max_element(begin(d1), end(d1)));

    debug(n1, d1);
    debug(n2, d2);

    for(int i = 0; i < n; i++){
        st[d1[i]].emplace(i);
        st[d2[i]].emplace(i);
    }

    for(int i = n; i > 0; i--){
        res[i] = n + 1;
        if(i > diam) continue;
        if(i < n) res[i] = res[i + 1];
        for(auto u : st[i]){
            if(curr.count(u)) continue;
            curr.emplace(u);
            res[i]--;
        }
    }

    for(int i = 1; i <= n; i++) cout << min(n, res[i]) << " ";
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
