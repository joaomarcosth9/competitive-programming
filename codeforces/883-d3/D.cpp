#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long double ld;

ld area(ld b1, ld b2, ld h) { return (ld(b1) + ld(b2)) * ld(h) / 2.0; }

int n;
ld d, h;

void solve() {
    cin >> n >> d >> h;
    vector<ld> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(rbegin(a), rend(a));
    ld res = 0;
    vector<bool> computed(n);
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            int h1 = a[i], h2 = a[i + 1];
            if (!computed[i]) {
                res += ld(d) * h / 2;
                debug(i, res);
                computed[i] = 1;
            }
            if (!computed[i + 1] && h2 + h > h1) {
                int nh = h1 - h2;
                ld prop = 1.0 - (ld(nh) / ld(h));
                debug(nh, prop, prop * d);
                res += area(d, prop * (d), nh);
                debug(i + 1, res);
                computed[i + 1] = 1;
            }
        } else {
            if (!computed[i]) {
                res += ld(d) * h / 2;
                computed[i] = 1;
            }
        }
    }
    cout << setprecision(10) << fixed << res << '\n';
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
