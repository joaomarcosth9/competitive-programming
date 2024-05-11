#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n), pref(n + 1), ones(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
        ones[i + 1] = ones[i] + (a[i] == 1);
    }
    auto qry = [&] (int l, int r) {
        return pref[r + 1] - pref[l];
    };
    auto qryones = [&] (int l, int r) {
        return ones[r + 1] - ones[l];
    };
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int len = (r - l + 1);
        int o = qryones(l, r);
        int sum = qry(l, r);

        int now = o * 2 + (len - o);

        if (len == 1) {
            cout << "NO" << endl;
            continue;
        }

        if (now > sum) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
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
