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
    ll n, k;
    cin >> n >> k;

    auto val = [&] (ll x) {
        ll val = k + x - 1;
        ll pref = (k + val) * (x) / 2;
        ll suff = (val + 1 + k + n - 1) * (n - x) / 2;
        return abs(pref - suff);
    };

    ll res = 1e18, pref = 0, suff = (k + (k + n - 1)) * (n) / 2;

    for (int i = 0; i <= min(5LL, n); i++) {
        res = min(res, abs(pref - suff));
        pref += k + i;
        suff -= k + i;
    }

    pref = (k + (k + n - 1)) * (n) / 2, suff = 0;

    for (int i = n - 1; i >= max(-1LL, n - 6); i--) {
        res = min(res, abs(pref - suff));
        suff += k + i;
        pref -= k + i;
    }

    ll l = 1, r = n - 1;

    while (l <= r) {
        ll mid = (l + r) / 2;
        ll mid2 = mid + 1;
        while (val(mid2) == val(mid)) mid2++;
        assert(mid2 <= n);
        if (val(mid) < val(mid2)) {
            res = min(res, val(mid));
            r = mid - 1;
        } else {
            res = min(res, val(mid2));
            l = mid2 + 1;
        }
    }

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
