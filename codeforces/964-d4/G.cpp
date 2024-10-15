#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
using ll = long long;
#define int ll

void solve() {
#ifdef LOCAL_DEBUG
int X; cin >> X;
#endif

    auto ask = [&] (int l, int r) {
        cout << "? " << l << " " << r << endl;
#ifdef LOCAL_DEBUG
        if (l >= X) {
            l++;
        }
        if (r >= X) {
            r++;
        }
        return l * r;
#else 
        int ret;
        cin >> ret;
        return ret;
#endif
    };

    int L = 2, R = 999, ans = -1;

    while (L <= R) {
        int mid1 = L + (R - L) / 3;
        int mid2 = L + (R - L) * 2 / 3;
        int area = ask(mid1, mid2);
        if (area == (mid1 * mid2)) {
            ans = mid2;
            L = mid2 + 1;
        } else if (area == (mid1 + 1) * (mid2 + 1)) {
            R = mid1 - 1;
        } else if (area == mid1 * (mid2 + 1)) {
            ans = mid1;
            L = mid1 + 1;
            R = mid2 - 1;
        } else if (area == (mid1 + 1) * mid2) {
            assert(false);
        }
    }

    cout << "! " << (ans == -1 ? 2 : ans + 1) << endl;
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