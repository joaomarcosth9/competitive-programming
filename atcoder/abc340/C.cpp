#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

map<ll, ll> dp;

ll solve(ll x) {
    if (x < 2) return 0;
    if (dp.count(x)) return dp[x];
    return dp[x] = x + solve(x / 2) + solve((x + 1) / 2);
}

void solve() {
    ll x; cin >> x;
    cout << solve(x) << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
