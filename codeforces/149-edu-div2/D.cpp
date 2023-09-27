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
    int c1 = 0, c2 = 0;
    for (auto u : s) {
        c1 += u == '(';
        c2 += u != '(';
    }
    if (c1 != c2) {
        cout << -1 << '\n';
        return;
    }
    auto a = s;
    reverse(begin(a), end(a));
    debug(s);
    debug(a);
    int st1 = 0;
    int st2 = 0;
    vector<int> co(n, 2);
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (st2 && s[i] == '(') {
            st2--;
            continue;
        }
        st1 += s[i] == '(';
        st1 -= s[i] == ')';
        if (st1 < 0) {
            res = 2;
            st2++;
            st1 = 0;
            continue;
        }
        co[i] = 1;
    }
    if (co == vector<int>(n, 2)) {
        res = 1;
        co = vector<int>(n, 1);
    }
    cout << res << '\n';
    for (auto u : co) cout << u << " ";
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
