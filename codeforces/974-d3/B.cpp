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
    int n, k;
    cin >> n >> k;

    bool even = false;

    if (n & 1) {
        even |= k % 4 == 3 || k % 4 == 0;
    } else {
        even |= k % 4 == 1 || k % 4 == 0;
    }

    cout << (even ? "Yes" : "No") << endl;
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