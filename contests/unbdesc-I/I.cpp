#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(3, 1e9));
    for(int& a : v){
        cin >> a; a++;
    }
    dp[0][2] = (v[0] != 2);
    for(int i = 1; i < n; i++){
        dp[i][0] = (v[i] != 0) + min(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = (v[i] != 1) + min(dp[i-1][1], dp[i-1][2]);
        dp[i][2] = (v[i] != 2) + dp[i-1][2];
    }
    cout << dp[n-1][0] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
