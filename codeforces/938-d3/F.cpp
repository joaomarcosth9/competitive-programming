#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 201;
int dp[N][N][N];

int dpp(int i, int j, int k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    bool now = ((i & 1 ? 1 : 0) ^ (j & 1 ? 2 : 0) ^ (k & 1 ? 3 : 0)) == 0;
    return dp[i][j][k] = now + max({dpp(i - 1, j, k), dpp(i, j - 1, k), dpp(i, j, k - 1)});
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    dp[0][0][0] = 0;
    dpp(200, 200, 200);
    while (TC--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << dp[a][b][c] + (d / 2) << endl;
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
