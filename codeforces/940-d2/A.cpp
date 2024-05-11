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
    map<int, int> f;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f[x]++;
    }
    int ans = 0;
    for (auto [k, v] : f) {
        if (v <= 2) continue;
        ans += v / 3;
    }
    cout << ans << endl;
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
