#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 1e5 + 5, mod = 1e9 + 7;
int n;
long long dp[maxn][2];
vector<int> adj[maxn];

void dfs(int u = 0) {
    if(adj[u].empty()){
        dp[u][0] = dp[u][1] = 1;
        return;
    }
    for(int v : adj[u]) {
        dfs(v);
    }
    int N = adj[u].size();
    vector<int> pref(N);
    pref[0] = dp[adj[u][0]][0];
    vector<int> suf(N);
    suf.back() = dp[adj[u].back()][0];
    for(int i = 1; i < N; i++){
        pref[i] = pref[i - 1] * dp[adj[u][i]][0] % mod;
        suf[N - 1 - i] = suf[N - i] * dp[adj[u][N - 1 - i]][0] % mod;
    }
    dp[u][0] += pref.back();
    for(int i = 0; i < N; i++){
        long long curr = dp[adj[u][i]][1];
        if(i > 0) curr = curr * pref[i - 1] % mod;
        if(i < N - 1) curr = curr * suf[i + 1] % mod;
        dp[u][0] = (dp[u][0] + curr) % mod;
        dp[u][1] = (dp[u][1] + curr) % mod;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p; cin >> p; --p;
        adj[p].push_back(i);
    }
    dfs();
    cout << dp[0][0] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
