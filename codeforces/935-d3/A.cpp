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
    int a, b, c; cin >> a >> b >> c;
    int res = a + (b / 3);
    b %= 3;
    if (b > 0 && (b + c < 3)) {
        cout << -1 << endl;
        return;
    } else {
        b += c;
        res += (b + 2) / 3;
    }
    cout << res << endl;
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
