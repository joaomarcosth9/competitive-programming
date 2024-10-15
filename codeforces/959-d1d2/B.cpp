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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int f1 = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            f1 = i;
            break;
        }
    }
    for (int i = 0; i < f1; i++) {
        if (s[i] != t[i]) return 0;
    }
    return 1;
    // 0001.....
    // xxxxyyyyy
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        // cout << solve() << endl;
        cout << (solve() ? "Yes" : "No") << endl;
    }
}