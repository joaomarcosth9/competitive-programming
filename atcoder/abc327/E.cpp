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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    a.insert(begin(a), -1);
    vector dp(n + 1, vector<double> (n + 1));
    vector<double> den(n + 1);
    den[1] = 1; 
    for (int i = 2; i <= n; i++) {
        den[i] = den[i - 1] * 0.9 + 1;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max({dp[i][j], dp[i - 1][j - 1] * 0.9 + a[i], dp[i - 1][j]});
        }
    }
    double res = -2e9;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[n][i] / den[i] - (1200 / sqrt(i)));
    }
    cout << setprecision(10) << fixed << res << endl;
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
