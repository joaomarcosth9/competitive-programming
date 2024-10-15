#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
const int INF = 2e9;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = (int)s.size(), m = (int)t.size();

    int res = n + m;

    int l = 0;

    for (int i = 0; i < min(n, m); i++) {
        if (s[i] != t[i]) {
            break;
        } else {
            l++;
        }
    }

    cout << res - (l ? l - 1: 0) << endl;
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