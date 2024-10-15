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
    int n, a, b; cin >> n >> a >> b;
    if (b <= a) {
        cout << (ll)n * a << endl;
    } else {
        ll d = 0;
        if (b - a > n) {
            d = (ll)(n) * (b - a + (b - a - n + 1)) / 2;
        } else {
            d = (ll)(b - a) * (b - a + 1) / 2;
        }
        cout << (ll)n * a + d << endl;
    }
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