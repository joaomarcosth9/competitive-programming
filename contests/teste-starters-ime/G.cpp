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
    int n; ll k; cin >> n >> k;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    k *= k;

    int l = 1, r = int(1e9), ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i] / mid;
        }
        if (sum >= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
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