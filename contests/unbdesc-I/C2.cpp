#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

long long calc(int s, int n) {
    vector dp(s, vector(n + 1, vector<long long>(n + 1)));
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[0][i][j] = 1;
        }
    }
    for (int i = 1; i < s; i++) {
        dp[i] = dp[i - 1];
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dp[i][j][k] = dp[i][j][k - 1];
                if (k <= j) dp[i][j][k] += dp[i - 1][j - k][k];
            }
        }
    }
    return dp[s - 1][n][n];
}

void solve() {
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 1; i * i <= n; i++) {
        int nn = n - (i * i);
        if (nn & 1) continue;
        res += calc(i, nn / 2);
    }
    cout << res << '\n';
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
