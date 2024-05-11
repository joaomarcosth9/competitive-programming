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
    int n; cin >> n;
    vector<pair<string, string>> a(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        string t; cin >> t;
        a[i].first = s;
        a[i].second = t;
    }

    vector can(n, vector (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            can[i][j] |= a[i].first == a[j].first;
            can[i][j] |= a[i].second == a[j].second;
        }
    }

    vector dp(1 << n, vector (n, (int)2e9));

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;
            for (int k = 0; k < n; k++) {
                if ((i >> k) & 1) continue;
                if (can[k][j]) dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j]);
                dp[i | (1 << k)][j] = min(dp[i | (1 << k)][j], dp[i][j] + 1);
            }
        }
    }

    int res = 2e9;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[(1 << n) - 1][i]);
    }
    cout << res << endl;

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
