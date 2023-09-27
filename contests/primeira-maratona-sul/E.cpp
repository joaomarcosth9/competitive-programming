#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 3e4 + 10;
vector<int> adj[maxn];

void dfs(int u){
    cout << "Olhando " << u << endl;
    for(int v : adj[u]) dfs(v);
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < 2 * n; i++){
        for(int j = 0; j < 6; j++){
            int u; cin >> u; u--;
            adj[i].emplace_back(u);
            cout << i << " " << u << endl;
        }
    }
    for(int i = 0; i < 2 * n; i++){
        cout << "I: " << i << endl;
        for(int v : adj[i]) cout << v << " ";
        cout << endl;
    }
    dfs(3);
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
