#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    double a, b;
    cin >> a >> b;
    double curr = 100.0;
    curr += curr * a / 100;
    curr += curr * b / 100;
    cout << setprecision(6) << fixed << curr - 100.0 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
