#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 1;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#define endl '\n'
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &a : v) cin >> a;
    v.push_back(0);
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    dp[1][0] = v[0];
    dp[1][1] = -v[0];
    db(dp[1][0], dp[1][1]);
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(-v[i - 1] + dp[i - 1][1], v[i - 1] + dp[i - 1][0]);
        dp[i][1] = max(v[i - 1] + dp[i - 1][1], -v[i - 1] + dp[i - 1][0]);
        db(i, dp[i][0], dp[i][1]);
    }
    cout << dp[n][0] << endl;
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
