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
    vector a(n + 1, vector<int> (n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> a[i][j];
        }
    }

    if (n == 1) {
        if (k == 1) {
            cout << (a[0][0] >= 0 ? a[0][0] : 0) << endl;
        } else {
            int first = a[0][0] >= 0 ? a[0][0] : 0 << endl;
            int second = a[0][0] ^ first;
            cout << first << " " << second << endl;
        }
        return;
    }

    vector<multiset<int>> dp(n + 1);
    dp[1].insert(0);
    dp[1].insert(a[0][0]);
    dp[2].insert(0);
    dp[2].insert(a[0][0]);
    dp[2].insert(a[0][1]);
    dp[2].insert(a[1][1]);

    for (int i = 2; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
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
