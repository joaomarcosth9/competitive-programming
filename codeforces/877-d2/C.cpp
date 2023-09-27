#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define int long long
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    bool s = 0;
    if (n == 4) {
        swap(n, m);
        s = 1;
    }
    vector<vector<int>> mat(n, vector<int>(m));
    int c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = c++;
        }
    }
    debug(mat);
    vector<int> order;
    for (int i = 1; i <= n; i += 2) {
        order.emplace_back(i);
    }
    for (int i = 2; i <= n; i += 2) {
        order.emplace_back(i);
    }
    debug(order);
    vector<vector<int>> res;
    for (int i = 0; i < n; i++) {
        auto linha = order[i] - 1;
        res.emplace_back(mat[linha]);
    }
    debug(res);
    if (!s) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << res[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                cout << res[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
