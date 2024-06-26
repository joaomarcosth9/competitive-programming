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
    string s; cin >> s;
    string t1, t2;
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] >= '0' && s[i + 1] <= '9' && s[i] >= 'a' && s[i] <= 'z') {
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            t1 += s[i];
        } else {
            t2 += s[i];
        }
    }
    return is_sorted(t1.begin(), t1.end()) && is_sorted(t2.begin(), t2.end());
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