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
    int n, x, y; cin >> n >> x >> y;
    x--; y--;

    vector<int> a(n, 1);
    for (int i = y - 1, cur = -1; i >= 0; i--, cur *= -1) {
        a[i] = cur;
    }
    for (int i = x + 1, cur = -1; i < n; i++, cur *= -1) {
        a[i] = cur;
    }

#ifdef LOCAL_DEBUG
    int mx_suff = -1e9, mx_pref = -1e9, id_mx_suff = -1, id_mx_pref = -1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > mx_pref) {
            mx_pref = sum;
            id_mx_pref = i;
        }
    }
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if (sum > mx_suff) {
            mx_suff = sum;
            id_mx_suff = i;
        }
    }
    if (id_mx_pref == x && id_mx_suff == y) {
        cout << "OK" << endl;
    } else {
        cout << "FAIL" << endl;
        cout << x + 1 << " " << y + 1 << endl;
        cout << id_mx_pref + 1 << " " << id_mx_suff + 1 << endl;
    }
#endif
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
