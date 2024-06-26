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
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    debug(a);
    while (q--) {
        int x; cin >> x;
        if (x == n) {
            cout << b.back() << " ";
            continue;
        }

        auto le = (int)(upper_bound(a.begin(), a.end(), x) - a.begin()) - 1;

        int dist = a[le + 1] - a[le];
        int time = b[le + 1] - b[le];

        debug(x, dist, time, (double)dist / time);

        cout << ll(b[le] + ((ll)x - a[le]) * time / dist) << " ";
    }
    cout << endl;
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
