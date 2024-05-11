#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

map<vector<vector<int>>, ll> dp;

void calc(vector<vector<int>> grid, vector<int> row, vector<int> col) {
    int n = (int)grid.size();
    if (row == vector<int>(n, 1) && col == vector<int>(n, 1)) {
        dp[grid] = 1;
        return;
    }
    // im going to place a rook in any place that doesnt attack any other rook
    // the computer will mirror my moves if it can
    // if it cant, it will do nothing
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (row[i] == 0 && col[i] == 0) {
            for (int j = 0; j < n; j++) {
                if (row[i] == 0 && col[j] == 0) {
                    if (i == j) {
                        grid[i][j] = 1;
                        row[i] = 1;
                        col[i] = 1;
                        calc(grid, row, col);
                        grid[i][j] = 0;
                        row[i] = 0;
                        col[i] = 0;
                    } else {
                        grid[i][j] = 1;
                        grid[j][i] = 2;
                        row[i] = row[j] = 1;
                        col[i] = col[j] = 1;
                        calc(grid, row, col);
                        grid[i][j] = 0;
                        grid[j][i] = 0;
                        row[i] = row[j] = 0;
                        col[i] = col[j] = 0;
                    }
                }
            }
        }
    }

}

ll brute(int x) {
    vector<vector<int>> grid(x, vector<int>(x, 0));
    vector<int> row(x, 0), col(x, 0);
    calc(grid, row, col);
    return 0;
}

const int MAX = 3e5 + 5, MOD = (int)1e9 + 7;
ll dpp[MAX];

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> vis(n + 1);
    int cnt = n;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        assert(vis[x] == 0);
        assert(vis[y] == 0);
        vis[x] = 1;
        vis[y] = 1;
        if (x == y) {
            cnt--;
        } else {
            cnt -= 2;
        }
    }
    cout << dpp[cnt] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    dpp[0] = 1;
    dpp[1] = 1;
    for (ll i = 2; i < MAX; i++) {
        dpp[i] = (dpp[i - 1] + (2 * (i - 1) * dpp[i - 2]) % MOD) % MOD;
    }
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
