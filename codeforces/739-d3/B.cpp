#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int r = abs(a - b);
    int l;
    if (c > r) {
        l = c - r;
    } else {
        l = c + r;
    }
    db(r, l);
    if (a > r * 2 || b > r * 2 || c > r * 2) {
        cout << -1 << endl;
        return;
    }
    if (l > r * 2 || l == c || l == a || l == b)
        cout << -1 << endl;
    else
        cout << l << endl;
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
