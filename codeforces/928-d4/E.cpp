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
    ll n, k; cin >> n >> k;
    ll N = n;
    ll pot = 1;
    for (int i = 1; i <= n; i *= 2) {
        ll now = (N + 1) / 2;
        if (k <= now) {
            cout << (1ll + 2ll * (k - 1)) * pot << endl;
            break;
        } else {
            k -= now;
            N /= 2;
        }
        pot *= 2;
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
