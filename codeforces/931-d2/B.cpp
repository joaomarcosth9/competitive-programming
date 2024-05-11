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
    int res = 2e9;
    for (int o = 0; o <= 3; o++) {
        for (int t = 0; t <= 2; t++) {
            for (int s = 0; s <= 5; s++) {
                for (int tn = 0; tn <= 3; tn++) {
                    int now = o * 1 + t * 3 + s * 6 + tn * 10;
                    if (now > n) continue;
                    if ((n - now) % 15 == 0) {
                        res = min(res, (n - now) / 15 + o + t + s + tn);
                    }
                }
            }
        }
    }
    cout << res << endl;
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
