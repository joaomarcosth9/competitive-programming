#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    ll each = accumulate(begin(a), end(a), 0ll) / n;

    for (int i = 0; i < n; i++) {
        if (a[i] < each) {
            return 0;
        }
        if (i < n - 1) {
            ll add = a[i] - each;
            a[i] = each;
            a[i + 1] += add;
        }
    }
    return true;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
