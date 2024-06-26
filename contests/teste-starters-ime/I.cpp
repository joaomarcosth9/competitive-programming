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
    int n; cin >> n;
    vector<int> a(n + 1), pmax(n + 1, INT_MIN), smin(n + 2, INT_MAX);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pmax[i] = max(pmax[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        smin[i] = min(smin[i + 1], a[i]);
    }
    int res = n;
    for (int i = 1; i < n; i++) {
        if (smin[i + 1] < a[i]) {
            break;
        } else {
            res--;
        }
    }
    for (int i = n; i > 1; i--) {
        if (pmax[i - 1] > a[i]) {
            break;
        } else {
            res--;
        }
    }
    if (n == 1) res = 0;
    cout << max(0, res) << endl;
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