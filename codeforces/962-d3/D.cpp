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
    int n, x; cin >> n >> x;
    ll res = 0;
    for (int a = 1; a <= n; a++) {
        for (int bpc = 2; bpc <= n / a; bpc++) {
            if (a + bpc > x) break;
            int has = a * bpc;
            int need = n - has;
            if (need < 0) break;
            debug(a, bpc);
            // b * c <= need
            int l = 1, r = bpc / 2;
            // b <= c
            while (l <= r) {
                int mid = (l + r) / 2;
                if ((ll)mid * (bpc - mid) <= need) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (r >= 1) res += r;
            l = (bpc / 2 + 1), r = bpc - 1;
            // b > c
            while (l <= r) {
                int mid = (l + r) / 2;
                if ((ll)mid * (bpc - mid) <= need) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (l <= bpc - 1) res += (bpc - 1) - l + 1;
        }
    }
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