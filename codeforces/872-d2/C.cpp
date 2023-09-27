#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    vector<int> has(m + 1);
    int fleft = 0;
    int fright = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] > 0) {
            has[v[i]] = 1;
        } else if (v[i] == -1) {
            // left
            fleft++;
        } else {
            fright++;
        }
    }

    vector<int> pf(m + 1);
    for (int i = 0; i < m; i++) {
        pf[i + 1] = pf[i] + has[i + 1];
    }

    auto query = [&](int l, int r) { return pf[r] - pf[l  -  1]; };

    auto calc = [&](int val) {
        int res = 1;
        int toleft = val - 1;
        int toright = m - val;
        if (fleft >= toleft) {
            res += toleft;
        } else {
            int can = query(1, val - 1);
            int templeft = fleft + can;
            res += min(templeft, toleft);
        }
        if (fright >= toright) {
            res += toright;
        } else {
            int can = query(val + 1, m);
            int tempright = fright + can;
            res += min(tempright, toright);
        }
        return res;
    };

    int RES = 0;

    RES = max(RES, min(m, fleft + query(1, m)));
    RES = max(RES, min(m, fright + query(1, m)));

    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            RES = max(RES, calc(v[i]));
        }
    }

    cout << RES << '\n';
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
