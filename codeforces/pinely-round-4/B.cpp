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
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n - 1; i++) {
        a[i] |= b[i];
        a[i + 1] |= b[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] & a[i + 1]) != b[i]) {
            cout << -1 << endl;
            return;
        }
    }
    for (auto u : a) {
        cout << u << " ";
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