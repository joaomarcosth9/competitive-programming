#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

void solve() {
    vector<int> a(35);
    a[0] = 1, a[1] = 2;
    for (int i = 2; i <= 30; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[30] << '\n';
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
