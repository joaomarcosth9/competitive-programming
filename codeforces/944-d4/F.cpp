#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

ll count(int y, int rad) {
    int l = 0, r = 2e5;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int dis = sqrtl((ll)y * y + (ll)mid * mid);
        if (dis < rad) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res += (count(i, n + 1) - count(i, n));
    }
    cout << res * 4 << endl;
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
