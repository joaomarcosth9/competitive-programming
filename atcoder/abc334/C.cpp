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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> f(n, 2);
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        x--;
        f[x]--;
    }

    int res = 0;
    vector<int> c(k + 1);

    int it = 1;
    debug(f);
    for (int i = 0; i < n; i++) {
        if (f[i] == 1) {
            debug(i);
            for (int j = i + 1; j < n; j++) {
                if (f[j] == 1) {
                    c[it] = j - i;
                    i = j - 1;
                    break;
                }
            }
            it++;
        }
    }

    vector dp(k + 1, vector (2, vector (2, vector<ll> (2, 2e9))));
    dp[1][0][0][0] = 0;
    dp[1][0][1][1] = 0;

    for (int i = 1; i < k; i++) {
        dp[i + 1][0][0][0] = dp[i][1][0][0];
        dp[i + 1][1][0][0] = dp[i][0][0][0] + c[i];

        dp[i + 1][0][1][1] = dp[i][1][0][0];

        dp[i + 1][0][1][0] = min(dp[i][0][1][1], dp[i][1][1][0]);
        dp[i + 1][1][1][0] = dp[i][0][1][0] + c[i];
    }

    cout << min({dp[k][0][k & 1][0], dp[k][0][k & 1][1], dp[k][1][k & 1][0]}) << endl;
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
