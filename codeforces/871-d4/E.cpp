#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 1005;
int n, m;
bool vis[maxn][maxn];
int grid[maxn][maxn];
long long sum = 0;

pair<int, int> moves[] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

inline bool valid(int i, int j) { return i >= 0 && j >= 0 && j < m && i < n && !vis[i][j] && grid[i][j] > 0; }

void dfs(int i, int j) {
    vis[i][j] = 1;
    sum += grid[i][j];
    for (auto [y, x] : moves)
        if (valid(i + y, j + x)) {
            dfs(i + y, j + x);
        }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
            cin >> grid[i][j];
        }
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (valid(i, j)) {
                sum = 0;
                dfs(i, j);
                res = max(res, sum);
            }
    }
    cout << res << '\n';
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
