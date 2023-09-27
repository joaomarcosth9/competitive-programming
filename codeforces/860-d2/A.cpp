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
    vector<int> a(n), b(n);
    for (int &u : a) cin >> u;
    for (int &u : b) cin >> u;
    int db = 1;
    int ma = a.back(), mb = b.back();
    db(ma, mb);
    for (int j = 0; j < n - 1; j++) {
        int aj = a[j], bj = b[j];
        if (ma < aj || mb < bj) {
            swap(aj, bj);
            if (ma < aj || mb < bj) {
                db = 0;
            }
        }
    }
    ma = b.back(), mb = a.back();
    for (int j = 0; j < n - 1; j++) {
        int aj = a[j], bj = b[j];
        if (ma < aj || mb < bj) {
            swap(aj, bj);
            if (ma < aj || mb < bj) {
                db = 0;
            }
        }
    }
    if (db) {
        cout << "yes" << endl;
        return;
    }
    cout << "no" << endl;
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
