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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    ll res = 1e18;
    ll now = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i < m) {
            res = min(res, now + a[i]);
        }
        now += min(a[i], b[i]);
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
