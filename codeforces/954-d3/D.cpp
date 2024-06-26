#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    for (auto &c : s) 
        c -= 48;

    ll res = LLONG_MAX;

    for (int i = 0; i < n - 1; i++) {
        ll p = s[i] * 10 + s[i + 1];
        vector<ll> nums;
        for (int j = 0; j < i; j++) {
            nums.push_back(s[j]);
        }
        nums.push_back(p);
        for (int j = i + 2; j < n; j++) {
            nums.push_back(s[j]);
        }
        debug(nums);
        ll cur = accumulate(nums.begin(), nums.end(), 0ll);
        for (auto &u : nums) {
            cur -= u == 1;
        }
        if (cur == 0) {
            cur = 1;
        }
        if (count(nums.begin(), nums.end(), 0)) {
            cur = 0;
        }
        res = min(res, cur);
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
