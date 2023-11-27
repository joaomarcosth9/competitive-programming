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

const int mod = 998244353;

void solve() {
    int n, a0, x, y, m, k; cin >> n >> a0 >> x >> y >> m >> k;
    vector<int> a(n);
    a[0] = a0 % m;
    for (int i = 1; i < n; i++) {
        a[i] = ((ll)a[i - 1] * x + y) % m;
    }

    vector dp(n + 1, vector<int> (k + 1));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = (a[i - 1] + dp[i - 1][0]) % mod;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j > 1) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
            else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) res ^= (1ll * dp[i][k] * i);
    cout << res << endl;

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
