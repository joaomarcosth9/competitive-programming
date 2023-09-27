#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

const ll p = 1e12 + 1, INF = 1e18;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (auto &u : s) u -= '0';
    int c0 = 0, c1 = 0;
    vector<array<ll, 2>> dp(n + 1, {INF, INF});
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (s[i] >= j) {
                dp[i + 1][s[i]] = min(dp[i + 1][s[i]], dp[i][j]);
            }
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + p);
            if (i + 1 < n && j <= s[i + 1] && s[i + 1] <= s[i]) {
                dp[i + 2][s[i]] = min(dp[i + 2][s[i]], dp[i][j] + p - 1);
            }
        }
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
