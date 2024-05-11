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
    int n; cin >> n;
    for (int ops = 1; ops <= 2 * n; ops++) {
        vector<vector<int>> a(n, vector<int> (n));
        for (int j = 0; j < (1 << ops); j++) {
            for (int k = 0; k < ops; k++) {
                if (j & (1 << k)) {

                } else {

                }
            }
        }
    }
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
