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
    int a, b, c; cin >> a >> b >> c;
    if (a + 1 != c) {
        cout << -1 << endl;
    } else {
        int d1 = 0, d2 = 0;
        int q1 = c, q2 = 0;

        d1 += b / c;
        b %= c;

        if (b) {
            d1++;
            d2 = d1 - 1;
            q1 = b;
            q2 = c - b;
        }

        debug(a, b, c);
        debug(d1, d2, q1, q2);

        while (a) {
            debug(a, d1, d2, q1, q2);
            if (q2 > 0 && q2 % 2 == 0) {
                a -= q2 / 2;
                q1 += q2 / 2;
                q2 = 0;
                d2 = 0;
            } else if (q2 > 0 && q2 % 2 == 1) {
                a -= q2 / 2;
                q1 += q2 / 2;
                q2 = 0;
                d2 = 0;
                a--;
                d2 = d1;
                q2 = q1 - 1;
                d1 = d2 + 1;
                q1 = 1;
            } else if (q1 % 2 == 0) {
                a -= q1 / 2;
                q1 = q1 / 2;
                d1++;
                q2 = 0;
                d2 = 0;
            } else if (q1 % 2 == 1) {
                a -= q1 / 2;
                q1 = q1 / 2;
                d1++;
                a--;
                d2 = d1;
                q2 = q1 - 1;
                d1 = d2 + 1;
                q1 = 1;
            } else {
                assert(false);
            }
        }

        cout << d1 << endl;

    }
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
