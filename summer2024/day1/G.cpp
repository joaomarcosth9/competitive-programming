#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e6 + 5, LG = 22;
int ALL = (1 << LG) - 1;
int n, dp[1 << LG], a[N];

void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int y = a[i] ^ ALL;
        dp[y] = a[i];
    }
    for (int m = ALL; m >= 0; m--) {
        for (int b = 0; b < LG; b++) if ((m >> b) & 1) {
            dp[m ^ (1 << b)] = max(dp[m ^ (1 << b)], dp[m]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[a[i]] << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
