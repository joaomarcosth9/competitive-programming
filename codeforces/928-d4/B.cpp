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
    int n; cin >> n;
    vector grid(n, vector<int> (n));
    ll minn = 1e9, maxx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            grid[i][j] = c - '0';
        }
        if (count(begin(grid[i]), end(grid[i]), 1)) {
            minn = min<ll>(minn, count(begin(grid[i]), end(grid[i]), 1));
            maxx = max<ll>(maxx, count(begin(grid[i]), end(grid[i]), 1));
        }
    }
    cout << (minn == maxx ? "SQUARE" : "TRIANGLE") << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
