#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 3005;
long long a[maxn];
long long dp[maxn][maxn];

long long dpp(int l, int r, int p) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    long long L = dpp(l + 1, r, !p);
    long long R = dpp(l, r - 1, !p);
    if (p == 0) { // eu sou o x do (x - y)
        return dp[l][r] = max(a[l] + L, a[r] + R);
    } else {
        return dp[l][r] = min(-a[l] + L, -a[r] + R);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << dpp(0, n - 1, 0) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
