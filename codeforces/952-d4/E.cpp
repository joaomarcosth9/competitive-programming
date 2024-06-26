#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

#define int ll

void solve() {
    int x, y, z, k; cin >> x >> y >> z >> k;
    int res = 0;
    for (int xx = 1; xx <= x; xx++) {
        for (int yy = 1; yy <= y; yy++) {
            int S = xx * yy;
            if (k % S == 0) {
                int now = 0;
                int f = (x - xx + 1);
                int g = (y - yy + 1);
                int zz = k / S;
                now = f * g * (z - zz + 1);
                res = max(res, now);
            }
        }
    }
    cout << res << endl;
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