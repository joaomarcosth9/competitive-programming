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
    int n, m, x; cin >> n >> m >> x;
    x--;

    vector<bool> dp(n + 1);
    dp[x] = 1;

    for (int i = 0; i < m; i++) {
        int k; char c; cin >> k >> c;

        vector<bool> new_dp(n + 1);

        for (int j = 0; j < n; j++) if (dp[j]) {
            if (c == '?' || c == '0') {
                new_dp[(j + k) % n] = 1;
            }
            if (c == '?' || c == '1') {
                new_dp[(j - k + n) % n] = 1;
            }
        }

        dp = new_dp;
    }

    set<int> poss;

    for (int i = 0; i < n; i++) {
        if (dp[i]) poss.insert(i);
    }

    cout << poss.size() << endl;
    for (auto u : poss) cout << u + 1 << " ";
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
