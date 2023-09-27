#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int mod = 998244353;

auto solve() -> void {
    long long n;
    cin >> n;
    long long res = 0;
    for (long long u = 1; u * u <= n; u++) {
        long long x = (n + (u * u)) / (2 * u);
        // u <= cara <= x
        x -= (u - 1);
        res = (res + x) % mod;
    }
    cout << res << '\n';
}

auto main() -> signed {
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
