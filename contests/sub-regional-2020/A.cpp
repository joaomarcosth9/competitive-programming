#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long double> dp(1000006);
    dp[0] = 0;
    long double m = (b - a + 1);
    long double pref = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;

        if (i >= max(1, a)) {
            pref += dp[i - max(1, a)];
            if (i > b) pref -= dp[i - b - 1];
        }
        dp[i] += pref / m;

        if (a == 0) {
            dp[i] /= (1.0 - 1.0 / m);
        }
    }
    cout << setprecision(10) << fixed << dp[n] << endl;
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
