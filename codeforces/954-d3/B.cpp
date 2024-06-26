#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> a(n, vector<int> (m));
    for (auto &u : a) {
        for (auto &v : u) {
            cin >> v;
        }
    }

    vector<pair<int, int>> moves = {
        {0, 1}, {-1, 0}, {0, -1}, {1, 0}
    };

    auto valid = [&] (int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = 0;
            for (auto [x, y] : moves) {
                if (valid(i + x, j + y)) {
                    mx = max(mx, a[i + x][j + y]);
                }
            }
            if (mx >= a[i][j])
                continue;
            a[i][j] = mx;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

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