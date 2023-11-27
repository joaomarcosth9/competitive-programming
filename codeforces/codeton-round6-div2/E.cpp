#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define endl '\n'
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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector dp(n + 2, vector<bool> (2 * n + 2));
    vector mex(n + 2, vector<int> (n + 2));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<ii>> good(n + 1);

    for (int i = 1; i <= n; i++) {
        int cmex = 0;
        vector<int> vis(n + 1);
        for (int j = i; j <= n; j++) {
            vis[a[j]] = 1;
            while (vis[cmex]) cmex++;
            mex[i][j] = cmex;
        }
    }

    for (int i = 1; i <= n; i++) {
        good[i].eb(i, mex[i][i]);
        for (int j = i + 1; j <= n; j++) {
            if (mex[i][j] > mex[i + 1][j] && mex[i][j] > mex[i][j - 1]) good[j].eb(i, mex[i][j]);
        }
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j <= 2 * n; j++) {
            for (auto [where, k] : good[i]) {
                dp[i][k ^ j] = dp[i][k ^ j] || dp[where - 1][j];
            }
        }
    }

    int ans = 0;
    for (int k = 0; k <= 2 * n; k++) if (dp[n][k]) ans = k;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            /* cout << solve() << endl; */
            /* cout << (solve() ? "YES" : "NO") << endl; */
            ++TEST;
        }
    } else solve();
}
