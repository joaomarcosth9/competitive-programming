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
    int n; cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[0][i] == '.') {
            if (a[1][i] == '.' && a[0][i - 1] == '.' && a[0][i + 1] == '.' 
                && a[1][i - 1] == 'x' && a[1][i + 1] == 'x') {
                res++;
            }
        }
    }for (int i = 1; i < n - 1; i++) {
        if (a[1][i] == '.') {
            if (a[0][i] == '.' && a[1][i - 1] == '.' && a[1][i + 1] == '.' 
                && a[0][i - 1] == 'x' && a[0][i + 1] == 'x') {
                res++;
            }
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