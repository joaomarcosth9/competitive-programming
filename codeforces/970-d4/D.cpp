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
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    map<int, int> f;
    map<int, map<int, int>> f2;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        a[i] = {x, y};
        f[x]++;
        f2[x][y] = 1;
    }
    ll res = 0;
    ll cur = 0, cur2 = n;
    for (auto [x, fq] : f) {
        cur2 -= fq;
        if (fq == 2) {
            res += cur + cur2;
        }
        cur += fq;
    }
    for (auto [x, f3] : f2) {
        for (auto [y, has] : f3) {
            if (!has) continue;
            res += f2[x + 1][y ^ 1] && f2[x - 1][y ^ 1];
        }
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
