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
    int n, k; cin >> n >> k;
    debug(bin(k, 10));
    if (n == 1) {
        cout << k << endl;
        return;
    }
    vector<int> ans;
    int lg = 31 - __builtin_clz(k);
    ans.push_back((1 << lg) - 1);
    k -= (1 << lg) - 1;
    ans.push_back(k);
    for (int i = 0; i < n - 2; i++) {
        ans.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
