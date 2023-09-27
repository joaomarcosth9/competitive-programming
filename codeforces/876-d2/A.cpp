#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n, k;
    cin >> n >> k;
    int res = 0;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int c = (i + k - 1) / k;
        int has = 0;
        debug(i, v);
        for (int j = i; j > 0; j--) {
            has += v[j];
        }
        for (int j = i; has < c; j--, has++) {
            v[j] = 1;
        }
        has = 0;
        for (int j = n - i + 1; j <= n; j++) {
            has += v[j];
        }
        for (int j = n - i + 1; has < c; j++, has++) {
            v[j] = 1;
        }
        debug(i, v);
    }
    cout << accumulate(begin(v), end(v), 0) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
