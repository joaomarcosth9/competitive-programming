#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &a : v) cin >> a;
    int ev = 0, od = 0;
    for (int &a : v) {
        ev += (a & 1 ? 0 : a);
        od += (a & 1 ? a : 0);
    }
    cout << (ev > od ? "YES" : "NO") << endl;
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
