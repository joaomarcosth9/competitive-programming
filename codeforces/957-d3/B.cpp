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
    ll res = 0;
    vector<int> a(k);
    int mx = -1;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
        res += a[i] - 1;
    }
    res -= (mx - 1);
    res += (n - mx);
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}