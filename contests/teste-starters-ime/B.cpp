#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    string s; cin >> s;
    int n = int(s.size());
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) return 1;
    }
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == s[i + 2]) return 1;
    }
    return 0;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        // cout << solve() << endl;
        cout << (solve() ? "yes" : "no") << endl;
    }
}