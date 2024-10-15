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
    int n, k;

    cin >> n >> k;

    int res = 0, gold = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= k) {
            gold += x;
        } else if (x == 0 && gold > 0) {
            gold--;
            res++;
        }
    }

    cout << res << endl;
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