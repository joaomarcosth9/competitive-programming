#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long double ld;

void solve() {
    int n; cin >> n;
    vector<ld> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];
    vector dp(n + 1, vector<ld>(n + 1));
    // dp[i][j] -> probabilidade de ter exatamente j heads ate a moeda i
    dp[1][1] = p[1];
    dp[1][0] = 1.0 - p[1];
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] += dp[i - 1][j] * (1.0 - p[i]);
            if(j > 0) dp[i][j] += dp[i - 1][j - 1] * (p[i]);
        }
    }
    ld res = 0;
    for(int i = n; i > n / 2; i--){
        res += dp[n][i];
    }
    cout << setprecision(10) << fixed << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
