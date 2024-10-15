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
    if (n == 1) {
        cout << 0 << endl;
    } else {
        int res = 0;
        while (n > 1) {
            n -= k - 1;
            res++;
        }
        cout << res << endl;
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
