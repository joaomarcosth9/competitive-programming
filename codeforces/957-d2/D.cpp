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
    int n, m, c; cin >> n >> m >> c;
    vector a(n, vector<int> (m));
    vector b(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            b[i][j] = ch == '1' ? 1 : -1;
            a[i][j] *= b[i][j];
        }
    }
    int X = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            X += a[i][j];
        }
    }
    vector<int> deltas;
    int cur = 0;
    debug(X);
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            cur += b[i][j];
        }
    }
    vector<vector<int>> psums(n);
    vector<vector<int>> psums_col(m);
    for (int i = 0; i < n; i++) {
        psums[i].resize(m + 1);
        for (int j = 0; j < m; j++) {
            psums[i][j + 1] = psums[i][j] + b[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        psums_col[i].resize(n + 1);
        for (int j = 0; j < n; j++) {
            psums_col[i][j + 1] = psums_col[i][j] + b[j][i];
        }
    }
    auto query = [&] (int i, int l, int r) {
        return psums[i][r + 1] - psums[i][l];
    };
    auto query_cols = [&] (int i, int l, int r) {
        return psums_col[i][r + 1] - psums_col[i][l];
    };
    for (int col = c - 1; col < m; col++) {
        if (col >= c) {
            cur -= query_cols(col - c, 0, c - 1);
            cur += query_cols(col, 0, c - 1);
        }
        deltas.push_back(abs(cur));
        int cur2 = cur;
        for (int row = c; row < n; row++) {
            cur2 -= query(row - c, col - c + 1, col);
            cur2 += query(row, col - c + 1, col);
            deltas.push_back(abs(cur2));
        }
    }
    debug(deltas);
    int g = 0;
    for (int u : deltas) {
        g = gcd(g, u);
    }
    cout << ((g == 0 || (X % g)) && (X != 0) ? "NO" : "YES") << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}