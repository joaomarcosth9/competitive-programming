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

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> dp(2 * k + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        auto new_dp = dp;
        int l, c;
        cin >> l >> c;
        int add = 0, spend = 0;
        while (l > 0 && c > 0) {
            if (l > c) swap(l, c);

            spend += l;
            add++;
            if (c == 1) add++;

            for (int p = 2 * k - add; p >= 0; p--) {
                new_dp[p + add] = min(new_dp[p + add], dp[p] + spend);
            }
            c--;
        }
        swap(dp, new_dp);
    }

    ll r = *min_element(begin(dp) + k, end(dp));
    if (r == 2e9) r = -1;
    cout << r << endl;

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
