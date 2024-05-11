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
    int res = 0;
    char c = '?';
    for (int len = 1; len <= n / 2; len++) {
        int cnt_match = 0;
        for (int i = 0; i < len; i++) {
            cnt_match += s[i] == s[i + len] || s[i] == c || s[i + len] == c;
        }
        if (cnt_match == len) res = max(res, len * 2);
        for (int i = 1; i + 2 * len - 1 < n; i++) {
            cnt_match -= s[i - 1] == s[i + len - 1] || s[i - 1] == c || s[i + len - 1] == c;
            cnt_match += s[i + len - 1] == s[i + 2 * len - 1] || s[i + len - 1] == c || s[i + 2 * len - 1] == c;
            if (cnt_match == len) res = max(res, len * 2);
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
