#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 205;
int mat[maxn][maxn], n, m;
bool vis[maxn][maxn];

bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }

pair<int, int> moves[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int res = INT_MAX, ress = 0;

void dfs(int i, int j) {
    vis[i][j] = 1;
    ress++;
    for (pair<int, int> p : moves) {
        int x = p.first, y = p.second;
        int ii = i + x, jj = j + y;
        if (valid(ii, jj) && !vis[ii][jj] && mat[i][j] == mat[ii][jj]) {
            dfs(ii, jj);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                dfs(i, j);
                res = min(ress, res);
                ress = 0;
            }
        }
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
