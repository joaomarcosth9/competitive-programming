#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif
#define int long long

void solve() {
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int res = 0;
    int nu = n >> 1;
    if (x1 > nu) {
        x1 = n - x1 + 1;
    }
    if (y1 > nu) {
        y1 = n - y1 + 1;
    }
    if (x2 > nu) {
        x2 = n - x2 + 1;
    }
    if (y2 > nu) {
        y2 = n - y2 + 1;
    }
    x1 = min(x1, y1);
    y1 = min(x1, y1);
    x2 = min(x2, y2);
    y2 = min(x2, y2);
    db(x1, y1, x2, y2);
    cout << abs(x1 - x2) << endl;
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
