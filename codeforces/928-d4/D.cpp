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
    int n; cin >> n;
    vector<ll> a(n);
    map<int, int> f;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    ll res = n;
    for (int i = 0; i < n; i++) {
        if (f[a[i]] > 0) {
            ll need = a[i] ^ ((1ll << 31) - 1);
            if (f[need] > 0) {
                res--;
                f[a[i]]--;
                f[need]--;
            }
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
