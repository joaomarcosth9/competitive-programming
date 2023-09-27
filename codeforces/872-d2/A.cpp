#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

void solve() {
    string s;
    cin >> s;
    bool dr = 1;
    char u = s[0];
    for (auto a : s) {
        dr &= u == a;
    }
    if (dr) {
        cout << -1 << '\n';
    } else {
        cout << s.size() - 1 << '\n';
    }
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
