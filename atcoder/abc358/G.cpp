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

void solve() {
    int n, m, k; cin >> n >> m >> k;

    int ii, jj; cin >> ii >> jj;
    ii--; jj--;

    vector a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = k * a[ii][jj];

    vector dp(n * m + 1, vector (n, vector<int> (m, LLONG_MIN)));
    dp[0][ii][jj] = 0;

    pair<int, int> movs[] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int moves = 1; moves <= n * m; moves++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto [x, y] : movs) {
                    int ni = i + x, nj = j + y;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    dp[moves][i][j] = max(dp[moves][i][j], dp[moves - 1][ni][nj] + a[i][j]);
                }
            }
        }
    }

    for (int moves = 1; moves <= min(n * m, k); moves++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dp[moves][i][j] + (k - moves) * a[i][j]);
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
