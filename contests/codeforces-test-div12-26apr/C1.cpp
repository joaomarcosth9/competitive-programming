#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

#define int ll

void solve() {
    int n; ll k; cin >> n >> k;
    k = 0;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    ll l = 0, r = 1e18;

    while (l <= r) {
        ll mid = midpoint(l, r);
        ll need = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) need += mid - a[i];
        }
        if (need <= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    debug(ans);

    assert(ans == *min_element(a.begin(), a.end()));

    for (int i = 0; i < n; i++) {
        if (a[i] < ans) {
            k -= ans - a[i];
            a[i] = ans;
        }
        a[i] -= ans;
    }
    assert(k >= 0);
    
    debug(a);

    ll ans2 = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) ans2++;
    }

    debug(a);

    debug(ans2);

    cout << ans * n - (n - 1) + ans2 << endl;
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
