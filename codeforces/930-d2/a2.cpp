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
    for (ll n = (ll)1e9; n > 0; n--) {
        ll pos = 1;
        while (pos * 2 <= n) {
            pos *= 2;
        }
        ll x = log2(n);
        ll temp = pow(2, x);
        if (temp != pos) {
            cout << n << endl;
            cout << pos << endl;
            cout << temp << endl;
            break;
        }
        if (n % (int)(1e8) == 0) cout << "OK" << " " << n << endl;
    }
}

int32_t main() {
    /* cin.tie(0)->sync_with_stdio(0); */
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
