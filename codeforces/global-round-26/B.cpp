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
    ll x; cin >> x;
    debug(x);
    bool db = 1;
    ll carry = 0;
    while (x > 0) {
        ll now = x % 10;

        if (now == x) {
            if (now != 1) {
                cout << "NO" << endl;
                return;
            }
            break;
        }

        ll need = now - carry;

        debug(x, now, carry, need);

        if (need < 0 || need >= 9) {
            cout << "NO" << endl;
            return;
        }

        carry = 1;
        x /= 10;
    }

    cout << "YES" << endl;
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