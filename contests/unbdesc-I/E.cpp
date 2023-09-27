#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

const int maxn = 2e5 + 5, mod = 1e9 + 7;
ll a[maxn];

ll basis[64], sz = 0;

void insertVector(ll u) {
    for (int i = 0; i < 63; i++) {
        if (!(u & (1ll << i))) continue;
        if (!basis[i]) {
            basis[i] = u;
            sz++;
            return;
        }
        u ^= basis[i];
    }
}

ll binpow(ll b, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insertVector(a[i]);
    }
    cout << (binpow(2, n) - binpow(2, n - sz) + mod) % mod << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
