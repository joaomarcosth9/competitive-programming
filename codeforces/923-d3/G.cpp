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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int R = -1;
    int ans = 0;

    for (int pos = 0; pos < n; pos++) {
        debug(pos, R, ans);
        if (pos <= R) continue;
        ans++;
        for (int i = 0; i < n; i++) {
            debug(i, pos, i + a[i] - 1);
            if (i <= pos) {
                R = max(R, i + a[i] - 1);
            } else {
                if (i - a[i] + 1 <= pos) {
                    R = max(R, i);
                }
            }
        }
    }

    cout << ans << endl;
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
