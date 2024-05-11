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
int n;
int dp[2][N][3];
string a[2];

int dpp(int i, int j, int m) {
    if (i < 0 || j < 0 || i > 1 || j >= n) return 0;
    if (dp[i][j][m] != -1) return dp[i][j][m];

    bool can = 0;

    if (m == 0) { // free
        can |= dpp(i, j - 1, 1); // moving right from the left cell
        can |= dpp(i, j + 1, 2); // left from the right cell

    } else if (m == 1) { // has to go right
        can |= dpp(i, j - 1, 0);
        can |= dpp(i - 1, j, 0);
        can |= dpp(i + 1, j, 0);

        can &= a[i][j] == '>';
    } else { // left
        can = 0;
    }

    return dp[i][j][m] = can;
}

bool solve() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            for (int m = 0; m < 3; m++) {
                dp[i][j][m] = -1;
            }
        }
    }
    dp[0][0][0] = 1;
    return dpp(1, n - 1, 0);
    /* return dpp(1, n - 1, 0) || dpp(1, n - 1, 1) || dpp(1, n - 1, 2); */
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
