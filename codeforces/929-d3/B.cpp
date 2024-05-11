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
    vector<int> a(n);
    for (int &it : a) cin >> it;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    ll m = sum % 3;
    if (m == 0) {
        cout << 0 << endl;
        return;
    }
    if (m == 2) {
        cout << 1 << endl;
        return;
    } 
    bool found = 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] % 3) == 1) {
            found = 1;
            break;
        }
    }
    if (found) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
