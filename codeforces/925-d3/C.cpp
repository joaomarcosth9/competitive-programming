#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

ll solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll r1 = -1, val1 = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] != val1) {
            r1 = i;
            break;
        }
    }
    ll r2 = -1, val2 = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] != val2) {
            r2 = i;
            break;
        }
    }
    debug(r1, val1, r2, val2);
    if (val1 == val2) {
        if (r1 == -1) return 0;
        return (r2 - r1 + 1);
    } else {
        return min(n - r1, r2 + 1);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
