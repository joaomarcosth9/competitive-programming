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
    string s;
    cin >> s;
    map<string, bool> m;
    int res = 0;
    debug(s);
    debug(m);
    for (int i = 0; i < n - 1; i++) {
        if (m[s.substr(i, 2)]) {
            continue;
        } else {
            m[s.substr(i, 2)] = 1;
            res++;
        }
    }
    debug(m);
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
