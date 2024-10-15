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
    int n, s, m;
    cin >> n >> s >> m;
    int last = 0;
    bool res = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l - last >= s) {
            res = 1;
        }
        last = r;
    }
    res |= (m - last) >= s;
    return res;
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