#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    int res = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        if (!u)
            c++;
        else
            c = 0;
        res = max(res, c);
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
