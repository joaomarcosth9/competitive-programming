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
    int a[2], b[2];
    for (int i = 0; i < 2; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> b[i];
    }
    int res = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int si = i ^ 1, sj = j ^ 1;
            int pa = 0, pb = 0;
            if (a[i] > b[j]) {
                pa++;
            } else if (a[i] < b[j]) {
                pb++;
            }
            if (a[si] > b[sj]) {
                pa++;
            } else if (a[si] < b[sj]) {
                pb++;
            }
            res += pa > pb;
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
