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
    vector<int> vals;
    vector<vector<int>> mat(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            vals.push_back(mat[i][j]);
        }
    }
    rotate(vals.begin(), vals.begin() + 1, vals.end());
    auto b = mat;
    int it = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[i][j] = vals[it++];
        }
    }

    if (b == mat) {
        cout << -1 << endl;
    } else {
        for (auto u : b) {
            for (auto v : u) {
                cout << v << " ";
            }
            cout << endl;
        }
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