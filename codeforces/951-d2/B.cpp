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
    int x, y; cin >> x >> y;
    debug(x);
    // for (int i = 1; i <= 20; i++) {
    //     cout << i << " " << (i ^ x) << endl;
    // }
    x ^= y;
    debug(x ^ y, bin(x ^ y, 20));
    // for (int i = 1; i <= 20; i++) {
    //     cout << i << " " << (i ^ x ^ (x ^ y)) << endl;
    // }
    cout << (x & (-x)) << endl;
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