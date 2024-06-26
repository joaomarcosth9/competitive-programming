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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (is_sorted(a.begin(), a.end())) {
        cout << "YES" << endl;
    } else {
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());
        int ok = -1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] == mn && a[i] == mx) {
                ok = i + 1;
            }
        }
        if (ok >= 0) {
            rotate(a.begin(), a.begin() + ok, a.end());
            if (is_sorted(a.begin(), a.end())) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
