#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

#define int ll

void solve() {
    int n; cin >> n;
    int sum = 0, res = 0;
    map<int, int> f;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        f[x]++;
        sum += x;
        if (sum % 2) continue;
        res += f[sum / 2] > 0;
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