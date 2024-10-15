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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    sort(a.rbegin(), a.rend());

    ll last = -1;
    ll A = 0, B = 0;

    debug(a, k);

    for (int i = 0; i < n; i++) {
        debug(i, a[i], A, B);
        if (i & 1) {
            // bob
            assert(last != -1);
            assert(k >= 0);
            assert(last - a[i] >= 0);

            debug(k, last - a[i]);
            ll diff = last - a[i];
            a[i] += min(k, diff);
            k -= min(k, diff);
            B += a[i];

            debug(B, a[i]);

        } else {
            // alice

            last = a[i];
            A += a[i];

            debug(A, a[i]);
        }
    }

    cout << A - B << endl;
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
