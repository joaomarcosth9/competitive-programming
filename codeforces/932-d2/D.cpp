#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    int res = ((c + 1) * (c + 2)) / 2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(2);

    for (int i = 0; i < n; i++) {
        // how many pairs x,y (x > y) such that x + y = a[i] or x - y = a[i]

        if (a[i] & 1) {
            res -= (a[i] + 1) / 2 - p[1];
            res -= c - a[i];
            p[1]++;
        } else {
            res -= (a[i] + 2) / 2 - p[0];
            res -= c - a[i];
            p[0]++;
        }
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
