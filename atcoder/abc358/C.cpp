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
    int n, m; cin >> n >> m;

    vector<string> a(n);
    for (string &t : a)
        cin >> t;

    int res = n;
    for (int i = 0; i < (1 << n); i++) {
        int has = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < m; k++) {
                    if (a[j][k] == 'o') {
                        has |= 1 << k;
                    }
                }
            }
        }
        if (has == ((1 << m) - 1)) {
            res = min(res, __builtin_popcount(i));
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}