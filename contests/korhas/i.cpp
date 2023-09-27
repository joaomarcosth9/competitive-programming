#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    vector<int> dp1(n), dp2(n);
    dp1[0] = 1;
    dp2[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        dp1[i] = min(v[i], dp1[i - 1] + 1);
    }
    for (int i = n - 2; i >= 0; i--) {
        dp2[i] = min(v[i], dp2[i + 1] + 1);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, min(dp1[i], dp2[i]));
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
