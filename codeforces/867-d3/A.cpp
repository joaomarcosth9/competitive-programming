#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> v(n), in(n);
    int res = -1;
    int mxi = 0;

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cin >> in[i];

    for (int i = 0; i < n; i++) {
        int curr = v[i] + i;
        if (curr <= t) {
            if (in[i] > mxi) {
                mxi = in[i];
                res = i + 1;
            }
        }
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
