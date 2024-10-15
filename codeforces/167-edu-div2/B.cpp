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
    string a, b; cin >> a >> b;
    int res = (int)a.size() + (int)b.size();
    int m = (int)b.size();
    for (int start = 0; start < m; start++) {
        int itb = start;
        int now = (int)a.size();
        for (int i = 0; i < (int)a.size() && itb < m; i++) {
            if (a[i] == b[itb]) {
                itb++;
            }
        }
        res = min(res, now + m - itb + start);
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