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
const int INF = 1e9;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), w(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    vector dp(n + 1, vector<int> (2, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + (w[i] ? a[i] : 0);
        if (i >= k) {
            dp[i][1] = max(dp[i - k][0] + (pref[i] - pref[i - k]), dp[i - 1][1] + (w[i] ? a[i] : 0));
        }
    }
    cout << dp[n][1] << endl;
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
