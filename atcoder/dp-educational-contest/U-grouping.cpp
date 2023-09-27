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

const int maxn = 16;
ll dp[1 << maxn];
int n;
ll a[maxn][maxn];
ll val[1 << maxn];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        val[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (int k = j + 1; k < n; k++) {
                    if (i & (1 << k)) {
                        val[i] += a[j][k];
                    }
                }
            }
        }
    }

    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        debug(bin(i));
        for (int j = i; j > 0; j = (j - 1) & i) {
            dp[i] = max(dp[i], dp[i ^ j] + val[j]);
        }
    }

    cout << dp[(1 << n) - 1] << endl;

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
