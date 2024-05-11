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
    if (k == 1) {
        for (int i = 0; i < n; i++) cout << i + 1 << " ";
        cout << endl;
    } else if (k == n) {
        for (int i = 0; i < n; i++) cout << 1 << " ";
        cout << endl;
    } else cout << -1 << endl;
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
