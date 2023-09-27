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

const int maxn = 3005;
int n;
const int mod = 1e9 + 7;
int dp[maxn][maxn];
string s;

void solve() {
    cin >> n >> s;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        vector<int> pref(n + 1);
        for (int j = 1; j <= n; j++) {
            pref[j] = (0ll + pref[j - 1] + dp[i - 1][j]) % mod;
        }
        for (int j = 1; j <= i; j++) {
            if (s[i - 2] == '>') {
                dp[i][j] = (0ll + dp[i][j] + pref[i - 1] - pref[j - 1] + mod) % mod;
            } else {
                dp[i][j] = (0ll + dp[i][j] + pref[j - 1] + mod) % mod;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= n; j++) ans = (0ll + ans + dp[n][j]) % mod;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC)
        cin >> TC;
    else
        TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
