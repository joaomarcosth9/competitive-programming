#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

const ll p = 1e12 + 1;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) c0 += s[i] == '0';
    ll res = 1e18;

    for (int i = 0; i <= n; i++) {
        /* ll temp1 = c0 + c1; */
        /* debug(c0, c1); */
        /* res = min(res, p * temp1); */
        if (i > 0 && s[i] == '0' && s[i - 1] == '1') {
            ll temp2 = p - 1;
            res = min(res, temp2 + p * (c0 - 1 + c1 - 1));
        }
        if (i == n) break;
        c0 -= s[i] == '0';
        c1 += s[i] == '1';
    }

    cout << res << '\n';
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
