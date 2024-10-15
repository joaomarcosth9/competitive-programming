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
    int64_t b, c, d;
    cin >> b >> c >> d;

    // (0 | 0) - (0 & 0) = 0
    // (0 | 0) - (1 & 0) = 0
    // (1 | 0) - (0 & 0) = 1
    // (1 | 0) - (1 & 0) = 1

    // (0 | 1) - (0 & 1) = 1
    // (0 | 1) - (1 & 1) = 0
    // (1 | 1) - (0 & 1) = 1
    // (1 | 1) - (1 & 1) = 0

    int64_t a = 0;

    for (int i = 60; i >= 0; i--) {
        int D = (d >> i) & 1, B = (b >> i) & 1, C = (c >> i) & 1;
        bool ok = 0;
        for (int A = 0; A < 2; A++) {
            if ((B | A) - (C & A) == D) {
                a |= int64_t(A) << i;
                ok = 1;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return;
        }
    }

    cout << a << endl;
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