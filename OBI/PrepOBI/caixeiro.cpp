#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e3;

int n, dp[MAX][MAX], adj[MAX][MAX];

int dpp(int l, int r) {
    if (l == 1 || r == 1) {
        dp[l][r] = adj[l][r];
        return dp[l][r];
    }
    if (dp[l][r] != -1) return dp[l][r];
    int next = min(l, r) - 1;
    dp[l][r] = min(dpp(l, next) + adj[r][next], dpp(next, r) + adj[next][l]);
    return dp[l][r];
}

void solve() {
    cin >> n;
    int nc = (n * (n - 1)) / 2;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < nc; i++) {
        int c1, c2, t;
        cin >> c1 >> c2 >> t;
        adj[c1][c2] = t;
        adj[c2][c1] = t;
    }
    for (int i = 0; i < MAX; i++) {
        adj[i][n + 1] = 0;
        adj[n + 1][i] = 0;
    }
    cout << min(dpp(n + 1, n), dpp(n, n + 1)) << endl;
}

int main() {
    solve();
    return 0;
}
