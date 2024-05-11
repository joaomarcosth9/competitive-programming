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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    int res = 0;
    for (int &i : a) cin >> i;
    for (int &j : b) cin >> j;
    for (int &i : a) {
        for (int &j : b) {
            res += i + j <= k;
        }
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
