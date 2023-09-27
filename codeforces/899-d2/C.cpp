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
#define int ll

ll solve() {
    int n; cin >> n;
    vector<int> a(n); for (int &i : a) cin >> i;

    a.insert(begin(a), 0);
    vector dp(n + 1, vector<ll> (2, (ll)4e16));
    dp[1][0] = 0;
    dp[1][1] = a[1];

    for (int i = 2; i <= n; i++) {
        if (i & 1) {
            dp[i][1] = max({dp[i - 1][0] + a[i], dp[i - 1][1], dp[i - 1][0]});
            dp[i][0] = max({dp[i - 1][1], dp[i - 1][0]});
        } else {
            dp[i][1] = max({dp[i - 1][1], dp[i - 1][0]});
            dp[i][0] = max({dp[i - 1][1] + a[i], dp[i - 1][1], dp[i - 1][0]});
        }
    }

    return max(dp[n][0], dp[n][1]);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
