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
    vector<pair<ll, ll>> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(begin(a), end(a));
    cout << abs(a[1].second - a[0].second) * abs(a[2].first - a[1].first) << endl;
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
