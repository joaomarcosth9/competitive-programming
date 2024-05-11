#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int mod = (int)1e9 + 7;

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    vector<ll> dp(n);
    dp[0] = a[0];
    ll res = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        res = max(dp[i], res);
    }
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    if (res >= 0) {
        sum -= res;
        for (int i = 0; i < k; i++) {
            res = (res * 2) % mod;
        }
        res = sum + res;
    } else res = sum;
    res %= mod;
    res = (res + mod) % mod;
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
