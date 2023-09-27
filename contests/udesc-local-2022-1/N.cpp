#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

long long ks(long long W, vector<pair<long long,long long>>& v){
    int n = v.size();
    // {peso, valor}
    db(W);
    db(v);
    vector<vector<long long>> dp(n+1, vector<long long>(W+1));
    db(dp);
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= W; j++){
            if(v[i].first > j) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = max(dp[i][j], v[i].second + dp[i][j-v[i].first]);
            }
        }
    }
    db(dp);
    return dp[n][W];
}

void solve(){
    long long n, m, p; cin >> n >> m >> p;
    vector<long long> W(n);
    for(int i = 0; i < n; i++){
        cin >> W[i];
    }
    vector<vector<pair<long long,long long>>> cont(n);
    for(int i = 0; i < m; i++){
        long long w, v, k; cin >> w >> v >> k;
        k--;
        cont[k].emplace_back(w, v);
    }
    long long res = 0;
    vector<pair<long long,long long>> CONT(n);
    for(int i = 0; i < n; i++){
        CONT[i] = {W[i], ks(W[i], cont[i])};
    }
    db(CONT);
    res = ks(p, CONT);
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
