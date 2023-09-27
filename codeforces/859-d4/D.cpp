#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n), pf(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    auto pr = [&](int l, int r) {  return pf[r] - pf[l  -  1]; };
    for (int i = 0; i < n; i++) pf[i + 1] = pf[i] + (v[i] & 1);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << (((pr(1, n) - pr(l, r) + (r - l + 1) * (k & 1)) & 1) == 0 ? "NO" : "YES") << endl;
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
