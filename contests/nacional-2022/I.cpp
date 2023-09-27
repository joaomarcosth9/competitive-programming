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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 1e2 + 1;
int l, c;
int mat[maxn][maxn];
ii moves[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int res = 0;
bool vis[maxn][maxn];

bool valid(int i, int j, int curr) { return i >= 0 && j >= 0 && j < c && i < l && mat[i][j] > curr && !vis[i][j]; }

void bfs(int I, int J) {
    queue<ii> q;
    q.emplace(I, J);
    while (!q.empty()) {
        debug(q);
        auto &[i, j] = q.front();
        int curr = mat[i][j];
        q.pop();
        if (vis[i][j]) continue;
        res++;
        vis[i][j] = 1;
        for (auto [y, x] : moves) {
            if (valid(i + y, j + x, curr)) {
                q.emplace(i + y, j + x);
            }
        }
    }
}

void solve() {
    cin >> l >> c;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    int mres = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            bfs(i, j);
            mres = max(mres, res);
            res = 0;
            memset(vis, 0, sizeof(vis));
        }
    }
    cout << mres << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
