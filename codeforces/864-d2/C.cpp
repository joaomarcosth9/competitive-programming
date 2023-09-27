#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int x, y;
    int res1 = ask(1, 1);
    int res2 = ask(n, 1);
    int res3 = -1;
    if (res1 + res2 == n - 1) {
        x = res1 + 1;
        res3 = ask(x, 1);
        y = res3 + 1;
    } else if (res1 == res2) {
        y = res1 + 1;
        res3 = ask(1, y);
        x = res3 + 1;
    } else {
        x = res1 + 1;
        y = res2 + 1;
        res3 = ask(x, 1);
        if (res2 != res3) {
            y = res1 + 1;
            x = n - res2;
        }
    }
    cout << "! " << x << " " << y << endl;
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
