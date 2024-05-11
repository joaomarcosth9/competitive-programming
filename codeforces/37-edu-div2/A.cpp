#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(k);

    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    int res = a[0];

    for (int i = 1; i < k; i++) {
        res = max(res, 1 + (a[i] - a[i - 1]) / 2);
    }

    res = max(res, n - a[k - 1] + 1);

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
