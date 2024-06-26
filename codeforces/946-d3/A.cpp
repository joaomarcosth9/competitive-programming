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
    int x, y; cin >> x >> y;
    int res = 0;
    while (x or y) {
        res++;
        int qt = 15;
        if (y >= 2) {
            y -= 2;
            qt -= 8;
        } else if (y == 1) {
            y -= 1;
            qt -= 4;
        }
        x -= min(x, qt);
    }
    cout << res << endl;
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
