#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937_64 rng(time(NULL));

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        ll x = rng(), y = rng();

        a[l] ^= x;
        a[r] ^= x;

        a[1] ^= y;
        a[l] ^= y;
        a[r] ^= y;
    }
    for (int i = 1; i <= n; i++) {
        a[i] ^= a[i - 1];
    }
    map<ll, int> f;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        f[a[i]]++;
        res = max(res, f[a[i]]);
    }
    cout << n - res << endl;
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