#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

int ppc(int x) {
    return __builtin_popcount(x);
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] = min(a[i], 5);
        a[i] = (1 << a[i]) - 1;
    }

    int res = 0;

    for (int i = 1; i <= n; i++) {
        debug(i, bin(a[i], 5));
    }

    for (int i = 1; i <= n; i++) {
        debug(i, bin(a[i], 5));
        if (i < n && ppc(a[i]) <= 2) {
            for (int j = 0; j < 4; j++) {
                if (a[i] >> j & 1) {
                    a[i] &= ~(1 << j);
                    a[i] &= ~(1 << (j + 1));
                    a[i + 1] &= ~(1 << j);
                    a[i + 1] &= ~(1 << (j + 1));
                    res++;
                }
            }
        } else if (a[i] > 0) {
            res++;
            a[i] = 0;
        }
        assert(a[i] == 0);
    }

    cout << res << endl;
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
