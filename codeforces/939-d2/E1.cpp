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
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int l = 0, r = 1e9;
    int ans = 0;

    // how many full plays can i play until the first one die?

    while (l <= r) {
        int mid = midpoint(l, r);
        bool db = 1;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            if (j == n) j = 0;
            if ((ll)a[i] * mid >= a[j]) {
                db = 0;
            }
        }
        if (db) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    debug(a);
    debug(ans);

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