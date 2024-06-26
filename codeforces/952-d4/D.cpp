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
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (string &t : a) {
        cin >> t;
    }
    
    int res_i = -1, l_j = -1, r_j = -1, best = 0;

    for (int i = 0; i < n; i++) {
        auto &s = a[i];
        int now = 0, now_l = 0;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                if (now == 0) {
                    now_l = j;
                }
                now++;
            }
        }
        if (now > best) {
            best = now;
            res_i = i + 1;
            l_j = now_l + 1;
            r_j = l_j + now - 1;
        }
    }

    cout << res_i << " " << (l_j + r_j) / 2 << endl;

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