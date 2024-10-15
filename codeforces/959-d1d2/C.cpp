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
    int n, x; cin >> n >> x;
    vector<ll> a(n);
    for (ll &i : a) {
        cin >> i;
    }

    vector<ll> dp(n + 1);

    ll sum = 0;
    for (int i = n - 1, j = n - 1; i >= 0; i--) {
        sum += a[i];
        while (sum > x) {
            sum -= a[j--];
        }
        if (j < n - 1) dp[i] = 1 + dp[j + 2];
    }

    cout << ((ll)n * (n + 1) / 2) - accumulate(dp.begin(), dp.end(), 0LL) << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
