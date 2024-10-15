#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

int solve() {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    if (l > L) {
        swap(l, L);
        swap(r, R);
    }
    if (r < L) {
        return 1;
    }
    if (l == L) {
        if (R < r) {
            return (R - L + 1);
        } else if (R > r) {
            return (r - L + 1);
        } else {
            return (R - L);
        }
    } else if (l < L) {
        if (R < r) {
            return (R - L + 2);
        } else if (R > r) {
            return (r - L + 2);
        } else {
            return (R - L + 1);
        }
    }
    assert(false);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}