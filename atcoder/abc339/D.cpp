#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
using i5 = tuple<int, int, int, int, int>;

const int N = 65;
int n;
int a[N][N];
int dis[N][N][N][N];
pair<int, int> ini[2];
pair<int, int> moves[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n && a[i][j] != -1;
}

void solve() {
    ini[0] = ini[1] = {-1, -1};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char now; cin >> now;
            if (now == '#') {
                a[i][j] = -1;
            } else if (now == 'P') {
                if (ini[0].first == -1) ini[0] = {i, j};
                else ini[1] = {i, j};
            }
        }
    }
    memset(dis, 0x3f, sizeof dis);
    const int inf = dis[0][0][0][0];
    queue<i5> pq;
    pq.push({0, ini[0].first, ini[0].second, ini[1].first, ini[1].second});
    while (!pq.empty()) {
        auto [w, x1, y1, x2, y2] = pq.front();
        pq.pop();
        if (dis[x1][y1][x2][y2] <= w) continue;
        dis[x1][y1][x2][y2] = w;
        for (auto [x, y] : moves) {
            int nx1 = x1, ny1 = y1, nx2 = x2, ny2 = y2;
            if (valid(x + x1, y + y1)) nx1 += x, ny1 += y;
            if (valid(x + x2, y + y2)) nx2 += x, ny2 += y;
            if (dis[nx1][ny1][nx2][ny2] > w + 1) {
                pq.emplace(w + 1, nx1, ny1, nx2, ny2);
            }
        }
    }
    int res = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = min(res, dis[i][j][i][j]);
        }
    }
    cout << (res < inf ? res : -1) << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
