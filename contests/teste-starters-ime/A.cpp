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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll pref = 0;
    ll mn = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        pref += a[i];
        cout << max(ans, pref - mn) << " ";
        ans = max(ans, pref - mn);
        mn = min(mn, pref);
    }

    cout << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}