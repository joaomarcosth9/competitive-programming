#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long double ld;

void solve() {
    ld R, k, d;
    cin >> R >> k >> d;
    ld r = R * k;
    ld PI = acos(-1);
    ld Ac = PI * (R * R - r * r);
    ld x = 2 * (r * sin(PI / 3));
    ld At = x * x * sqrt(3) / 4;
    At = 3 * At / 4;
    ld Af = At + Ac;
    ld Vol = Af * 0.5;
    ld res = d * Vol;
    cout << setprecision(10) << fixed << res << '\n';
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
