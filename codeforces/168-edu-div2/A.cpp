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
    string s; cin >> s;
    int n = (int)s.size();
    if (n == 1) {
        cout << s;
        cout << char('a' + (s[0] == 'a'));
        cout << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            int c = s[i - 1] - 'a';
            cout << s.substr(0, i);
            cout << char('a' + (c + 1) % 26);
            cout << s.substr(i);
            cout << endl;
            return;
        }
    }
    cout << char(s[0] + (s[0] == 'z' ? -1 : 1)) << s << endl;
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