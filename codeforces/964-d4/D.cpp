#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    string t, s;
    cin >> s >> t;

    int n = (int)s.size();
    int m = (int)t.size();

    for (int i = 0, j = 0; j < m; j++) {
        debug(i, j, s[i], t[j]);
        while (i < n && (s[i] != t[j] && s[i] != '?')) {
            i++;
        }
        debug("after", i, j, s[i], t[j]);
        if (i == n) {
            cout << "NO" << endl;
            return;
        }
        if (s[i] == '?') {
            s[i] = t[j];
            i++;
        } else {
            i++;
        }
        debug(s, t);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') s[i] = 'a';
    }

    cout << "YES" << endl;
    cout << s << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}