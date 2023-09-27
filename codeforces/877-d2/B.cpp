#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int iidx = -1, nidx = -1, didx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) iidx = i + 1;
        if (a[i] == 2) didx = i + 1;
        if (a[i] == n) nidx = i + 1;
    }
    if (didx < nidx) {
        if (iidx > nidx) {
            cout << "1 1" << '\n';
        } else if (iidx < didx) {
            cout << didx << " " << nidx << '\n';
        } else {
            cout << iidx << " " << nidx << '\n';
        }
    } else {
        if (iidx < nidx) {
            cout << "1 1" << '\n';
        } else if (iidx > didx) {
            cout << didx << " " << nidx << '\n';
        } else {
            cout << iidx << " " << nidx << '\n';
        }
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
