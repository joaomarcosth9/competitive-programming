#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

ll solve() {
    int n; cin >> n;
    ll x, y; cin >> x >> y;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    ll res = 0;
    map<pair<ll, ll>, ll> f;
    for (int i = n - 1; i >= 0; i--) {
        ll rx = a[i] % x;
        ll ry = a[i] % y;
        ll need = (0 - rx + x) % x;
        res += f[make_pair(need, ry)];
        f[make_pair(rx, ry)]++;
    }
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
