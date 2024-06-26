#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int m, x; cin >> m >> x;
    vector<int> c(m), h(m);
    int sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        h[i] = 1;
        sum += h[i];
    }
    // m <= 2e5
    // sum <= 2e5
    vector dp(m + 1, vector<ll> (sum + 1, LLONG_MIN));
    dp[0][0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i + 1][j] = dp[i][j];
        }
        for (int j = 0; j + h[i] <= sum; j++) {
            if (dp[i][j] != LLONG_MIN) {
                dp[i + 1][j + h[i]] = max(dp[i + 1][j + h[i]], dp[i][j] - c[i]);
            }
        }
        debug(i, dp[i]);
    }
    for (int i = sum; i >= 0; i--) {
        if (dp[m][i] + x * (m) >= 0 || i == 0) {
            cout << i << endl;
            return;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
