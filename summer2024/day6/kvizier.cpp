#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
#define int ll

const int N = 4015;
int n, m, k;
int g[N][N], diagL[N][N], diagR[N][N], place[N][N];
bool valid(int i, int j) {
    return i >= 0 && i <= n + 1 && j >= 0 && j <= m + 1;
}

int vis[N][N];
int ts = 1;

pair<int, int> moves[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            place[i][j] = 1;
            char c; cin >> c;
            g[i][j] = (c == '.');
        }
    }

    queue<tuple<int, int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j]) {
                q.emplace(i, j, 0);
            }
        }
    }
    while (q.size()) {
        auto [i, j, steps] = q.front();
        q.pop();
        if (vis[i][j] == ts || steps > k) continue;
        vis[i][j] = ts;
        place[i][j] = 0;
        for (auto [x, y] : moves) if (valid(i + x, j + y) && vis[i + x][j + y] < ts) {
            if (place[i + x][j + y] == 0) continue;
            q.emplace(i + x, j + y, steps + 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (place[i][j]) {
                q.emplace(i, j, 0);
            }
        }
    }
    ts++;

    while (q.size()) {
        auto [i, j, steps] = q.front();
        q.pop();
        if (vis[i][j] == ts || steps > k) continue;
        vis[i][j] = ts;
        for (auto [x, y] : moves) if (valid(i + x, j + y) && vis[i + x][j + y] < ts) {
            q.emplace(i + x, j + y, steps + 1);
        }
    }

    bool db = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 0) {
                db &= vis[i][j] == ts;
            }
        }
    }

    cout << (db ? "YES" : "NO") << endl;

    ts++;

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * m; j++) {
            g[i][j] = diagL[i][j] = diagR[i][j] = place[i][j] = 0;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) solve();
}
