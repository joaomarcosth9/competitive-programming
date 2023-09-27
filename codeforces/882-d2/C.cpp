#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int maxn = 1e5 + 5;
int a[maxn];
bool dp[maxn][512];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < 512; j++) {
            dp[i][j] = 0;
        }
    }
    int res = 0;
    dp[0][a[0]] = 1;
    dp[0][0] = 1;
    res = max(res, a[0]);
    for (int i = 1; i < n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < 512; j++) {
            dp[i][j] = (dp[i - 1][j ^ a[i]]);
            if(dp[i][j]) res = max(res, j);
        }
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
