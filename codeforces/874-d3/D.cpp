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
    vector<int> p(n);
    for (auto &i : p) cin >> i;
    int nidx = -1;
    int search = n;
    if (p[0] == n) search = n - 1;
    for (int i = 0; i < n; i++) {
        if (p[i] == search) nidx = i;
    }
    vector<int> best(n);
    iota(begin(best), end(best), 1);
    debug(best);
    for (int l = 0; l <= nidx; l++) {
        int r = nidx;
        int r2 = nidx - 1;
        // [i, j]
        if (l <= r) {
            vector<int> tenta;
            for (int k = r + 1; k < n; k++) {
                tenta.emplace_back(p[k]);
            }
            for (int k = r; k >= l; k--) {
                tenta.emplace_back(p[k]);
            }
            for (int k = 0; k < l; k++) {
                tenta.emplace_back(p[k]);
            }
            if (tenta > best) {
                debug(l, r);
                swap(tenta, best);
            }
        }
        if (l <= r2) {
            vector<int> tenta;
            for (int k = r2 + 1; k < n; k++) {
                tenta.emplace_back(p[k]);
            }
            for (int k = r2; k >= l; k--) {
                tenta.emplace_back(p[k]);
            }
            for (int k = 0; k < l; k++) {
                tenta.emplace_back(p[k]);
            }
            if (tenta > best) {
                debug(l, r2);
                swap(tenta, best);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << best[i] << ' ';
    }
    cout << '\n';
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
