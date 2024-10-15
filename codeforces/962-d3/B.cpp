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
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x; cin >> x;
            if ((i % k) == 0 && (j % k) == 0) {
                cout << x;
            }
        }
        if (i % k == 0) cout << endl;
    }
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