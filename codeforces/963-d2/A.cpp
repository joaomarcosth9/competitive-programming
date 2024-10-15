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
    int n;
    string s;
    cin >> n >> s;

    map<char, int> f;

    int cnt = 0;

    for (int i = 0; i < 4 * n; i++) {
        f[s[i]]++;
        cnt += s[i] != '?';
    }

    int res = cnt;

    for (auto [k, v] : f) {
        if (k != '?') {
            res -= max(0, v - n);
        }
    }

    cout << res << endl;
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