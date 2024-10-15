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
    string s;
    cin >> s;

    if ((int)s.size() < 3) {
        return false;
    }

    if (s[0] != '1' || s[1] != '0') {
        return false;
    }

    if (s[2] == '0') {
        return false;
    }

    int x = stoi(s.substr(2));

    if (x >= 2) return true;

    return false;
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