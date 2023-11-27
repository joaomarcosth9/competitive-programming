#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

int n, m;

ii moves[] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void solve() {
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    int mni = INT_MAX, mnj = INT_MAX, mxi = -1, mxj = -1;

    vector dis(n, vector<int>(m, 2e9));
    queue<ii> q;

    for (int i = 0; i < n; i++) {
        if (q.size()) break;
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                dis[i][j] = 0;
                q.emplace(i, j);
                break;
            }
        }
    }

    while (q.size()) {
        auto [i, j] = q.front();
        mni = min(mni, i);
        mnj = min(mnj, j);
        mxi = max(mxi, i);
        mxj = max(mxj, j);
        q.pop();
        for (auto [y, x] : moves) {
            if (!valid(i + y, j + x)) continue;
            if (grid[i + y][j + x] == '#' && dis[i + y][j + x] > dis[i][j] + 1) {
                dis[i + y][j + x] = dis[i][j] + 1;
                q.emplace(i + y, j + x);
            }
        }
    }

    for (int i = mni; i <= mxi; i++) {
        for (int j = mnj; j <= mxj; j++) {
            if (grid[i][j] != '#') {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
