#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (n & 1) {
        s.erase(n / 2, 1);
    }
    char c = s[0];
    bool dr = 1;
    for (auto u : s) {
        dr &= u == c;
    }
    cout << (dr ? "NO" : "YES") << '\n';
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
