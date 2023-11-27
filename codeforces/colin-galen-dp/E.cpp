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
typedef vector<ll> vi;

const ll INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    ll office; cin >> office;
    vector<ll> a(n), b(k);

    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;

    a.insert(begin(a), -1);
    b.insert(begin(b), -1);

    sort(all(a));
    sort(all(b));

    debug(a);
    debug(b);

    vector dp(n + 1, vector<ll> (k + 1, INF));
    dp[0] = vector<ll> (k + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= k; j++) {
            dp[i][j] = min(dp[i][j - 1], max(dp[i - 1][j - 1], abs(a[i] - b[j]) + abs(b[j] - office)));
        }
        debug(dp[i]);
    }

    cout << dp[n][k] << endl;

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
