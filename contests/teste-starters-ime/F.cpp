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
    int n, m; ll a, b, c;
    cin >> n >> m >> a >> b >> c;
    string s, t;
    cin >> s >> t;

    const ll INF = (ll)1e18;
    vector dp(n + 1, vector<ll> (m + 1, INF));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = b * i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = a * j;
    }

    debug(0, dp[0]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + b);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + a);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : c));
            debug(i, j, dp[i][j]);
        }
    }

    cout << dp[n][m] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}