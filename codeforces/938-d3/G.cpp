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

    vector a(n, vector<int> (m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int g = gcd(a[0][0], a[n - 1][m - 1]);

    pair<int, int> moves[] = {
        {0, 1}, {1, 0}
    };

    vector vis(n, vector<bool> (m));
    auto b = a;

    auto test = [&] (int gc) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = (a[i][j] % gc) == 0;
                vis[i][j] = 0;
            }
        }

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        vis[0][0] = 1;

        auto valid = [&] (int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && b[i][j] == 1;
        };

        while (q.size()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto [x, y] : moves) {
                if (valid(i + x, j + y)) {
                    q.emplace(i + x, j + y);
                    vis[i + x][j + y] = 1;
                }
            }
        }

        return vis[n - 1][m - 1];

    };

    int ans = 0;

    for (int i = 1; i * i <= g; i++) {
        if (g % i) continue;
        if (test(i)) {
            ans = max(ans, i);
        }
        debug(test(i), ans, i);
        if (test(g / i)) {
            ans = max(ans, g / i);
        }
    }

    cout << ans << endl;

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