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

pair<int, int> moves[] = {
    {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

pair<int, vector<pair<int, int>>> dfs(int i, int j, int n, int m, int k, vector<vector<int>> &a) {
    if (k == 0) return {0, {}};
    int now = 0;
    vector<pair<int, int>> ret;
    for (auto [x, y] : moves) {
        int ii = i + x, jj = j + y;
        if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
        auto [val, path_] = dfs(ii, jj, n, m, k - 1, a);
        if (val + a[ii][jj] > now) {
            now = val + a[ii][jj];
            ret = path_;
        }
    }
    ret.push_back({i, j});
    return {now, ret};
}

void solve() {
    int n, m, k; cin >> n >> m >> k;

    int ii, jj; cin >> ii >> jj;
    ii--; jj--;

    vector a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    auto [res, path_] = dfs(ii, jj, n, m, k, a);

    cout << res << endl;
    reverse(path_.begin(), path_.end());

    for (int i = 0; i < (int)path_.size(); i++) {
        if (i > 0) cout << " -> ";
        cout << "(" << path_[i].first + 1 << ", " << path_[i].second + 1 << ")";
    }
    cout << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
