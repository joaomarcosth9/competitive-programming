#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 2e5 + 5;
const int K = 15;

ll dp[N][K];
int n, k;
ll a[N], b[N];

int c[N];

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = i;
    }

    sort(c, c + n, [&] (int i, int j) {
        return (a[i] * (a[j] + b[j]) + b[i]) < (a[j] * (a[i] + b[i]) + b[j]);
    });

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j < k) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], a[c[i]] * dp[i][j] + b[c[i]]);
            }
        }
    }

    cout << dp[n][k] << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}