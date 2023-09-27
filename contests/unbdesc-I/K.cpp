#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

int n, m;
vector<vector<int>> mat;
vector<vector<vector<int>>> dis;

pair<int, int> moves[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; }

void solve() {
    cin >> n >> m;

    mat.resize(n);
    dis.resize(n);
    for (int i = 0; i < n; i++) {
        mat[i].resize(m);
        dis[i].resize(m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int Q;
    cin >> Q;
    vector<int> qq(Q);
    for (int i = 0; i < Q; i++) {
        cin >> qq[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dis[i][j].assign(Q, 2e9);
        }
    }

    deque<tuple<int, int, int, int>> q;
    q.emplace_front(0, 0, 0, 0);
    dis[0][0][0] = 0;
    while (!q.empty()) {
        auto [i, j, d, cq] = q.front();
        q.pop_front();
        if (dis[i][j][cq] < d) continue;
        if (mat[i][j] == qq[cq]) {
            if (cq == Q - 1) {
                cout << d << '\n';
                break;
            }
            dis[i][j][cq + 1] = d;
            q.emplace_front(i, j, d, cq + 1);
            continue;
        }
        for (auto [y, x] : moves) {
            int ii = i + y, jj = j + x;
            if (valid(ii, jj) && dis[ii][jj][cq] > d + 1) {
                dis[ii][jj][cq] = d + 1;
                q.emplace_back(ii, jj, d + 1, cq);
            }
        }
    }
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
