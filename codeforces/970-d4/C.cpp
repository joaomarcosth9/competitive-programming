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
    ll x, y, k;
    cin >> x >> y >> k;
    ll rx = (x + k - 1) / k;
    ll ry = (y + k - 1) / k;
    ll res = 0;
    cout << max(rx, ry) * 2 - (rx > ry) << endl;
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
