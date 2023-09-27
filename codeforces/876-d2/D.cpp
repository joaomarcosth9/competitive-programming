#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    auto ov = v;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> pref(n), suf(n);
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + (v[i] < v[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + (v[i] < v[i + 1]);
    }
    debug(v);
    debug(pref);
    debug(suf);
    for (int k = 0; k <= n; k++) {
    }
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
