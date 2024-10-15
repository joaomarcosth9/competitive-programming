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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), pref(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    auto query = [&] (ll l, ll r, ll cyc) {
        ll zero = (n - cyc) % n;
        if (r < zero) {
            ll d0 = n - zero;
            l += d0, r += d0;
            assert(l >= 0 && r < n);
        } else if (l >= zero) {
            l -= zero, r -= zero;
            assert(l >= 0 && r < n);
        } else {
            r = (r - zero);
            l = n - (zero - l);
            swap(l, r);
            l++, r--;
            assert(l >= 0 && r < n);
            return pref[n] - (pref[r + 1] - pref[l]);
        }
        return pref[r + 1] - pref[l];
    };
    auto get_array = [&] (ll id) {
        return id / n;
    };

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        ll id_l = get_array(l), id_r = get_array(r);
        ll res = 0; 
        if (id_r - id_l > 1) {
            res += pref[n] * (id_r - id_l - 1);
        }
        l -= (id_l * n), r -= (id_r * n);
        if (id_l == id_r) {
            res += query(l, r, id_l);
        } else {
            res += query(l, n - 1, id_l) + query(0, r, id_r);
        }
        cout << res << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
