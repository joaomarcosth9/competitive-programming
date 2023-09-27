#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int X = INT_MAX;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n / 2; i++) {
        // v[i] == v[n-1-i] (mod x);
        int df = abs(v[i] - v[n - 1 - i]);
        // df == 0 (mod x);
        X = (X == INT_MAX ? df : gcd(df, X));
    }
    cout << (X == INT_MAX ? 0 : X) << '\n';
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
