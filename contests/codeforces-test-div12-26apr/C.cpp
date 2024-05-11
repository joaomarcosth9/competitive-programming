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

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;

    __int128 l = 0, r = 1e18;

    while (l <= r) {
        __int128 mid = l + (r - l) / 2;
        __int128 need = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < mid) need += mid - a[i];
        }
        if (need <= (__int128)k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    debug(ans);

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
        else if (k > 0) ans2++, k--; 
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
