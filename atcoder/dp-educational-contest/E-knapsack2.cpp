#include <bits/stdc++.h>

using namespace std;

long long dp[105][100005], v[105], w[105];
const long long INF = 1e18 + 5;

long long ks(int n, int c) {
    if (c < 0 || n < 0) return INF - 5;
    if (dp[n][c] != INF) return dp[n][c];
    if (c == 0 && n == 0) return dp[n][c] = 0;
    dp[n][c] = min(dp[n][c], ks(n - 1, c));
    if (v[n] <= c) {
        dp[n][c] = min(ks(n - 1, c), ks(n - 1, c - v[n]) + w[n]);
    }
    return dp[n][c];
}

int main() {
    int n, W;
    cin >> n >> W;
    long long max_v = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        max_v += v[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= max_v; j++) dp[i][j] = INF;
    }
    for (int i = 0; i <= max_v; i++) ks(n, i);
    long long maxx = -1;
    for (long long j = 1; j <= max_v; j++) {
        if (dp[n][j] <= W) maxx = max(maxx, j);
    }
    cout << maxx << endl;
    return 0;
}