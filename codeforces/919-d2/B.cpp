#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(rbegin(a), rend(a));

    ll res = -1e18;

    for (int i = 0; i < x; i++) {
        a[i] = -a[i];
    }

    ll now = accumulate(begin(a), end(a), 0ll);
    res = max(res, now);

    debug(a, now);

    for (int i = 0; i < k; i++) {
        now -= a[i];
        if (i + x < n) {
            now -= a[i + x];
            a[i + x] = -a[i + x];
            now += a[i + x];
        }
        res = max(res, now);
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
