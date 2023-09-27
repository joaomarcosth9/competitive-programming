#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long l = lcm(2, lcm(3, 5));
    a *= l;
    b *= l;
    c *= l;
    char u;
    cin >> u;
    if (u == 'A') {
        cout << (a + 3 * (b / 2) + 5 * (c / 2)) / l << endl;
    } else if (u == 'B') {
        cout << (b + 2 * (a / 3) + 5 * (c / 3)) / l << endl;
    } else if (u == 'C') {
        cout << (c + 2 * (a / 5) + 3 * (b / 5)) / l << endl;
    }
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
