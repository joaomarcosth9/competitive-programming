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
const ll INF = 1e9;

ll solve() {
    int n, m = 0; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (count(all(a), 0) <= 1) return 0;

    set<ll> st(begin(a), end(a));
    ll mex = 0;
    auto it = begin(st);
    while (it != end(st)) {
        if (*it == mex) mex++;
        else break;
        it++;
    }
    debug(mex);

    map<int, int> freq;
    for (ll u : a) freq[u] += 1;

    ll best = mex * n;
    vector<ll> mn(5001, INF);
    mn[mex] = 0;

    ll ac = 0;
    for (int i = 0; i <= n; i++) {
        if (!freq[i]) break;
        mn[i] = freq[i];
    }
    mn[mex] = 0;
    vector dp(mex + 1, INF);

    dp[mex] = 0;

    for (int i = mex; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            dp[j] = min(dp[j], j + dp[i] + i * (mn[j] - 1));
            debug(i, j, dp[j], dp[i], mn[j]);
        }
    }

    debug(dp);
    return dp[0];
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
