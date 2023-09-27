#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    const int N = 2e5 + 5;
    long long t;
    cin >> t;
    vector<long long> dp(N);
    vector<long long> og(N);
    vector<long long> need(N);
    dp[1] = 12;
    og[1] = 2;
    need[1] = 12;
    dp[2] = 18;
    og[2] = 4;
    need[2] = 18 + 1;
    for (long long i = 3; i < N; i++) {
        dp[i] = dp[i - 2] + 4 * i + 5;
        og[i] = og[i - 2] + 6;
        need[i] = dp[i] + (og[i] - 2) / 2;
    }
    long long T = 0;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        debug(u, need[u]);
        T += need[u];
    }
    debug(T, t);
    cout << max(0ll, T - t) << '\n';
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
