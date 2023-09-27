#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    long long res1 = 4, res2 = 4;
    res1 -= x1 == 0;
    res1 -= x1 == n - 1;
    res1 -= y1 == 0;
    res1 -= y1 == m - 1;
    res2 -= x2 == 0;
    res2 -= x2 == n - 1;
    res2 -= y2 == 0;
    res2 -= y2 == m - 1;
    cout << min(res1, res2) << endl;
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
