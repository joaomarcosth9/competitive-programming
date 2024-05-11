#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

ll gauss(ll l, ll r) {
    if (l > r) swap(l, r);
    return (r - l + 1) * (l + r) / 2;
}

void solve() {
    int n, K; cin >> n >> K;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    ll res = 0;

    map<ll, int, greater<>> f;
    for (int i = 0; i < n; i++) {
        f[a[i]]++;
    }

    while (f.size() > 1) {
        auto [k, v] = *f.begin();
        f.erase(f.begin());
        auto [k2, v2] = *f.begin();
        if (K >= (v * (k - k2))) {
            res += gauss(k, k2 + 1) * v;
            f[k2] += v;
            K -= v * (k - k2);
        } else {
            ll t = K / v;
            if (t >= 1) res += gauss(k, k - t + 1) * v;
            K %= v;
            res += K * (k - t);
            K = 0;
            break;
        }
    }

    if (f.size()) {
        auto [k, v] = *f.begin();
        if (K >= (v * k)) {
            res += gauss(k, 1) * v;
            K = 0;
        } else {
            debug(K, k, v);
            ll t = K / v;
            if (t >= 1) res += gauss(k, k - t + 1) * v;
            K %= v;
            res += K * (k - t);
        }
    }

    cout << res << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
