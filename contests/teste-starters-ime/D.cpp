#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = int(2e3) + 5;

pair<int, int> moves[] = {
    {0, -1}, {1, 0}, {-1, 0}, {0, 1}
};

int n, m;
char a[N][N];
int block[N][N], dist[N][N];
pair<int, int> pa[N][N];
vector<pair<int, int>> res_path;

void bfs(int ii, int jj) {
    memset(dist, 0x3f, sizeof dist);
    memset(pa, -1, sizeof pa);
    const int INF = dist[0][0];

    queue<pair<int, int>> q;
    if (!block[ii][jj]) {
        q.emplace(ii, jj);
        dist[ii][jj] = 0;
        pa[ii][jj] = {ii, jj};
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (auto [x, y] : moves) {
            int ni = i + x, nj = j + y;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !block[ni][nj]) {
                if (dist[ni][nj] > dist[i][j] + 1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    pa[ni][nj] = {i, j};
                }
            }
        }
    }
    if (dist[n - 1][m - 1] < INF) {
        int i = n - 1, j = m - 1;
        while (pa[i][j] != pair<int, int>(i, j)) {
            res_path.emplace_back(i, j);
            tie(i, j) = pa[i][j];
        }
        res_path.emplace_back(0, 0);
        for (auto [i1, j1] : res_path) {
            a[i1][j1] = 'X';
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] != '.') {
                block[i][j] = 2;
            }
        }
    }

    // should not pass
    // nvm, it should

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '>') {
                int k = j + 1;
                while (k < m && block[i][k] != 2) {
                    block[i][k++] = 1;
                }
            } else if (a[i][j] == '<') {
                int k = j - 1;
                while (k >= 0 && block[i][k] != 2) {
                    block[i][k--] = 1;
                }
            } else if (a[i][j] == 'v') {
                int k = i + 1;
                while (k < n && block[k][j] != 2) {
                    block[k++][j] = 1;
                }
            } else if (a[i][j] == '^') {
                int k = i - 1;
                while (k >= 0 && block[k][j] != 2) {
                    block[k--][j] = 1;
                }
            }
        }
    }

    bfs(0, 0);

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}