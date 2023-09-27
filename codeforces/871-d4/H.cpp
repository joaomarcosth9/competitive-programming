#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    debug(n, k);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<long long> dp(64);
    for (int i = 1; i <= n; i++) {
        auto new_dp = dp;
        new_dp[v[i]] = (new_dp[v[i]] + 1) % mod;
        for (int j = 0; j < 64; j++) {
            new_dp[j & v[i]] = (new_dp[j & v[i]] + dp[j]) % mod;
        }
        swap(new_dp, dp);
    }
    long long res = 0;
    for (int i = 0; i < 64; i++) {
        if (__builtin_popcount(i) != k) continue;
        res = (res + dp[i]) % mod;
    }
    cout << res << '\n';
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
