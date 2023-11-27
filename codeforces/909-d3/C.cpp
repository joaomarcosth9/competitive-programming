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
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = INT_MIN;
    vector<vector<int>> b;
    vector<int> now {a[0]};
    for (int i = 1; i < n; i++) {
        if ((a[i] & 1) == (now.back() & 1)) {
            b.eb(now);
            now.clear();
        }
        now.eb(a[i]);
    }
    if (now.size()) b.eb(now);

    auto kadani = [&] (vector<int> c) {
        int N = size(c);
        vector<int> dp(N);
        dp[0] = c[0];
        for (int i = 1; i < N; i++) {
            dp[i] = max(dp[i - 1] + c[i], c[i]);
        }
        return *max_element(all(dp));
    };

    for (auto u : b) res = max(res, kadani(u));
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
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
