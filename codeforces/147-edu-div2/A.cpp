#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    long long res = 1;
    if (s[0] == '0') {
        cout << 0 << '\n';
        return;
    }
    if (n == 1) {
        if (s[0] == '?') {
            cout << 9 << '\n';
        } else {
            cout << 1 << '\n';
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 && s[i] == '?') {
            res = 9;
        } else if (res == 1 && s[i] == '?') {
            res = 10;
        } else if (s[i] == '?') {
            res *= 10;
        }
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
