#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int u;
    cin >> u;
    string t;
    cin >> t;
    int v = t[0] - '0';
    if (v == 1) {
        cout << min(45, u);
        if (u > 45) {
            cout << "+" << u - 45;
        }
    } else {
        cout << min(90, 45 + u);
        if (u > 45) {
            cout << "+" << u - 45;
        }
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
