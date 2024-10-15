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
    int x, y, k; 
    cin >> x >> y >> k;
    ll sum = 0;
    for (int i = 1; i < k; i++) {
        cout << x + i << " " << y << endl;
        sum += x + i;
    }
    cout << x * k - sum << " " << y << endl;
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