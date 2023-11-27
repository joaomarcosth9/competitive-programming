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
const ll INF = 1e14L;

void solve() {
    int n; cin >> n;
    vector<pair<ll, int>> items;
    vector<ll> dp(1 << 3, INF);
    for (int i = 0; i < n; i++) {
        ll u; cin >> u;
        string s; cin >> s;
        int msk = 0;
        if (count(all(s), 'A')) msk |= 1 << 0;
        if (count(all(s), 'B')) msk |= 1 << 1;
        if (count(all(s), 'C')) msk |= 1 << 2;
        items.eb(u, msk);
    }
    dp[0] = 0;
    for (int mask = 0; mask < (1 << 3); mask++) {
        for (int i = 0; i < n; i++) {
            ll u = items[i].first;
            int msk = items[i].second;
            dp[mask | msk] = min(dp[mask | msk], u + dp[mask]);
        }
    }
    if (dp[(1 << 3) - 1] == INF) cout << -1 << endl;
    else cout << dp[(1 << 3) - 1] << endl;
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
