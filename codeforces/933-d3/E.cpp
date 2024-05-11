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
    int n, m, k, d; cin >> n >> m >> k >> d;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> all_dp(n, vector<ll> (m));
    vector<ll> cost(n, LLONG_MAX);

    for (int i = 0; i < n; i++) {
        auto &dp = all_dp[i];

        multiset<ll> dps;
        dp[0] = 1;
        dps.insert(dp[0]);

        for (int j = 1; j < m; j++) {
            if (j - (d + 2) >= 0) {
                dps.erase(dps.find(dp[j - (d + 2)]));
            }
            dp[j] = a[i][j] + 1 + *dps.begin();
            dps.insert(dp[j]);
        }

        cost[i] = dp[m - 1];
    }

    debug(cost);
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + cost[i];
    }

    ll ans = LLONG_MAX;

    for (int i = k; i <= n; i++) {
        ans = min(ans, pref[i] - pref[i - k]);
    }

    cout << ans << endl;

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
