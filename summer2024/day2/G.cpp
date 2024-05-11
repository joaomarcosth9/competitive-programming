#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 5050, INF = 1e9;
int n, a[N];
int dp[N][2 * N];

void solve() {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        // dp[i][j] -> menor custo pra chegar
        // no i-th cara com j 1's pendurados
        for (int j = -i; j <= i; j++) {
            if (a[i] == 1) {
                dp[i][j + N] = min(dp[i - 1][j - 1 + N] + abs(j - 1), dp[i][j + N]);
            } else {
                dp[i][j + N] = min(dp[i - 1][j + 1 + N] + abs(j + 1), dp[i - 1][j + N] + abs(j));
            }
        }
    }
    cout << dp[n][N] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][N] = 0;
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
