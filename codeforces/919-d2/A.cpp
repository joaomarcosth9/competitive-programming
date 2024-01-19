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
    int n; cin >> n;
    ll minK = -1e18, maxK = 1e18;
    vector<int> t;
    for (int i = 0; i < n; i++) {
        int ts; cin >> ts;
        ll x; cin >> x;
        if (ts == 1) {
            minK = max(minK, x);
        } else if (ts == 2) {
            maxK = min(maxK, x);
        } else {
            t.emplace_back(x);
        }
    }
    ll res = maxK - minK + 1;
    for (int x : t) {
        if (x >= minK && x <= maxK) res--;
    }
    if (maxK < minK) res = 0;
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
