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

const ll inf = 1e16;

void solve() {
    int n; cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<ll> pref(n + 1);

    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    vector dp(n + 1, -inf);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int gap = i - j - 1;
            dp[i] = max(dp[i], dp[j] + 2 * pref[gap / 2] + (gap & 1 ? a[gap / 2 + 1] : 0));
        }
        debug(i, dp[i]);
    }

    ll res = 0;

    for (int i = 1; i <= n; i++) {
        int gap = n - i;
        res = max(res, dp[i] + 2 * pref[gap / 2] + (gap & 1 ? a[gap / 2 + 1] : 0));
        debug(i, res);
    }

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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
