#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

int64_t sim(int64_t n) {
    int64_t sq = sqrtl(n);
    while (__int128_t(sq) * sq > n) sq--;
    while (__int128_t(sq + 1) * (sq + 1) <= n) sq++;
    return n - sq;
}

void solve() {
    int64_t k;
    cin >> k;

    int64_t l = 1, r = int64_t(2e18);

    while (l <= r) {
        int64_t mid = midpoint(l, r);
        if (sim(mid) >= k) r = mid - 1;
        else l = mid + 1;
    }

    cout << l << endl;
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