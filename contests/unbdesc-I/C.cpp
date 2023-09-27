#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i - (2 * j - 1) < 0) continue;
            dp[i][j] += dp[i - (2 * j - 1)][j - 1];
        }
    }
    cout << dp[n][n] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
