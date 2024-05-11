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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int> (m));
    pair<int, int> now = {0, 0};
    int curr = 0;
    vector<pair<int, int>> moves = {
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };
    for (int r = 0; r < k; r++) {
        auto &[i, j] = now;
        if (grid[i][j]) {
            grid[i][j] = 0;
            curr = (curr + 3) % 4;
            i = (i + moves[curr].first + n) % n;
            j = (j + moves[curr].second + m) % m;
        } else {
            grid[i][j] = 1;
            curr = (curr + 1) % 4;
            i = (i + moves[curr].first + n) % n;
            j = (j + moves[curr].second + m) % m;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (grid[i][j] ? "#" : ".");
        }
        cout << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
