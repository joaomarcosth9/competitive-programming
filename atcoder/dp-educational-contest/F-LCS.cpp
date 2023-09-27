#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 5e3;
string s, t;

pair<int, pair<int, int>> dp[maxn][maxn];

void solve() {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i + 1][j + 1];
                dp[i][j].first++, dp[i][j].second = {i, j};
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    string res;
    auto [size, ij] = dp[0][0];
    auto [i, j] = ij;

    for (; size; i = dp[i][j].second.first, j = dp[i][j].second.second, size--) {
        res.push_back(s[i]);
        i++, j++;
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
