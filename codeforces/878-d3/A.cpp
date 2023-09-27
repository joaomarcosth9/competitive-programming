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
    char u = s[0];
    int i;
    cout << s[0];
    for (i = 1; i < n; i++) {
        if (s[i] == u) {
            if (i < n - 1) cout << s[i + 1];
            i++;
            u = s[i];
        }
    }
    cout << '\n';
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
