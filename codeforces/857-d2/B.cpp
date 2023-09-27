#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n;
    cin >> n;
    int res = 0;

    int um = 0;

    int fr = 0, pigs = 0;

    int us = 0;

    for (int i = 0; i <= n; i++) {
        int a;
        if (i < n)
            cin >> a;
        else
            a = 2;
        db(a);
        if (a == 1) {
            pigs++;
            us++;
            if (fr)
                fr--;
            else
                res++;
            db(res, fr, pigs);
        } else if (a == 2) {
            if (pigs == 0) continue;
            if (pigs & 1) {
                us = (pigs + 1) >> 1;
            } else {
                us = (pigs >> 1) + 1;
            }
            fr = res - us;
            db(res, fr, pigs);
        }
    }
    cout << res << endl;
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
