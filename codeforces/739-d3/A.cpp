#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int k;
    cin >> k;
    int i = 1;
    int n = 1;
    while (1) {
        if (i == k) {
            cout << n << endl;
            return;
        }
        n++;
        if ((n % 3 != 0) && (n % 10 != 3)) i++;
    }
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
