#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 2e3 + 5, INF = 2e9;
int n, m;
char grid[maxn][maxn];
int no[maxn][maxn];
int dis[maxn][maxn];

bool valid(int i, int j) { return i >= 0 && j >= 0 && j < m && i < n && !no[i][j]; }

ii moves[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs(int I, int J) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dis[i][j] = INF;
        }
    }

    dis[I][J] = 0;
    queue<ii> q;
    q.emplace(I, J);
    while (q.size()) {
        auto [i, j] = q.front();
        q.pop();
        int w = dis[i][j];
        for (auto [y, x] : moves)
            if (valid(y + i, x + j)) {
                if (dis[y + i][x + j] > w + 1) {
                    dis[y + i][x + j] = w + 1;
                    q.emplace(y + i, x + j);
                }
            }
    }
}

void solve() {
    cin >> n >> m;
    int I, J, II, JJ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                I = i, J = j;
            else if (grid[i][j] == 'G')
                II = i, JJ = j;
        }
    }

    bool mark = 0;
    for (int i = 0; i < n; i++) {
        mark = 0;
        for (int j = 0; j < m; j++) {
            const char &c = grid[i][j];
            no[i][j] |= mark;
            if (c == '>') {
                mark = 1;
                no[i][j] = 1;
            } else if (c == '<' || c == 'v' || c == '^' || c == '#') {
                no[i][j] = 1;
                mark = 0;
            }
        }
    }

    mark = 0;
    for (int i = 0; i < n; i++) {
        mark = 0;
        for (int j = m - 1; j >= 0; j--) {
            const char &c = grid[i][j];
            no[i][j] |= mark;
            if (c == '<') {
                mark = 1;
                no[i][j] = 1;
            } else if (c == '>' || c == 'v' || c == '^' || c == '#') {
                no[i][j] = 1;
                mark = 0;
            }
        }
    }

    mark = 0;
    for (int j = 0; j < m; j++) {
        mark = 0;
        for (int i = 0; i < n; i++) {
            const char &c = grid[i][j];
            no[i][j] |= mark;
            if (c == 'v') {
                mark = 1;
                no[i][j] = 1;
            } else if (c == '>' || c == '<' || c == '^' || c == '#') {
                no[i][j] = 1;
                mark = 0;
            }
        }
    }

    mark = 0;
    for (int j = 0; j < m; j++) {
        mark = 0;
        for (int i = n - 1; i >= 0; i--) {
            const char &c = grid[i][j];
            no[i][j] |= mark;
            if (c == '^') {
                mark = 1;
                no[i][j] = 1;
            } else if (c == '>' || c == '<' || c == 'v' || c == '#') {
                no[i][j] = 1;
                mark = 0;
            }
        }
    }

    bfs(I, J);

    cout << (dis[II][JJ] == INF ? -1 : dis[II][JJ]) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}
