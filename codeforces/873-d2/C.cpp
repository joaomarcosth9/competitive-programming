#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(rbegin(a), rend(a));
    sort(rbegin(b), rend(b));
    debug(a);
    debug(b);
    long long res = 1;
    for (int i = 0; i < n; i++) {
        if (b[i] >= a[i]) {
            cout << 0 << '\n';
            return;
        }
        int L = i, R = n - 1;
        int ans = i;
        while (L <= R) {
            int mid = L + R >> 1;
            if (a[mid] > b[i]) {
                L = mid + 1;
                ans = mid;
            } else {
                R = mid - 1;
            }
        }
        res = res * ((ans + 1) - i) % mod;
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
