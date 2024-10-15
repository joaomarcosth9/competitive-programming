#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e5 + 5;

void solve() {
    int n, x; cin >> n >> x;
    // x <= 10^5
    vector<int> d;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            d.push_back(i);
            if (i != x / i) {
                d.push_back(x / i);
            }
        }
    }
    sort(d.rbegin(), d.rend());
    vector<int> a(n), good(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        good[i] = (x % a[i]) > 0;
    }
    int res = 1;
    map<int, int> dp;
    dp[1] = 1;
    for (int i = 0; i < n; i++) {
        debug(i, a[i], dp, res);
        if (good[i]) {
            continue;
        }
        for (auto u : d) {
            if (dp.count(u)) {
                if ((ll)u * a[i] <= x)
                    dp[u * a[i]] = 1;
            }
        }
        if (dp.count(x)) {
            res++;
            dp.clear();
            dp[1] = 1;
            dp[a[i]] = 1;
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}