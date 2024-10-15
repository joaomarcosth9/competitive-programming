#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n, m; cin >> n >> m;
    vector a(n, vector<int> (m));
    vector b(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            a[i][j] = c - 48;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            b[i][j] = c - 48;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            debug(i, j, a[i][j], b[i][j]);
            if ((a[i][j] + 1) % 3 == b[i][j]) {
                a[i][j]++;
                a[i][j] %= 3;

                a[i + 1][j + 1]++;
                a[i + 1][j + 1] %= 3;

                a[i + 1][j] += 2;
                a[i + 1][j] %= 3;

                a[i][j + 1] += 2;
                a[i][j + 1] %= 3;
            } else if ((a[i][j] + 2) % 3 == b[i][j]) {
                a[i][j] += 2;
                a[i][j] %= 3;

                a[i + 1][j + 1] += 2;
                a[i + 1][j + 1] %= 3;

                a[i + 1][j]++;
                a[i + 1][j] %= 3;

                a[i][j + 1]++;
                a[i][j + 1] %= 3;
            }
        }
    }

    return a == b;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        // cout << solve() << endl;
        cout << (solve() ? "Yes" : "No") << endl;
    }
}