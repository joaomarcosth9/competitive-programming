#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    int o1 = 1e9, o2 = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            if (a[i] < o2) o2 = a[i];
            if (o2 < o1) swap(o1, o2);
        }
    }
    vector<int> b = a;
    bool dbb = 0;
    bool db = 1;
    for (int i = 0; i < n; i++) {
        if ((b[i] % 2) == 0) continue;
        if (b[i] == o1) {
            if (b[i] <= o2) db = 0;
        } else {
            if (b[i] <= o1) db = 0;
        }
    }
    dbb |= db;
    db = 1;
    for (int i = 0; i < n; i++) {
        if ((b[i] % 2) == 1) continue;
        if (b[i] <= o1) db = 0;
    }
    dbb |= db;
    cout << (dbb ? "YES" : "NO") << '\n';
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
