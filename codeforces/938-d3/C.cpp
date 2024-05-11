#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n; ll k; cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    int l = 0, r = n - 1;
    int res = 0;
    while (l < r) {
        debug(l, r, a[l], a[r], res);
        if (a[l] == a[r]) {
            if (k >= 2 * a[l]) {
                k -= 2 * a[l];
                l++;
                r--;
                res += 2;
            } else {
                if (k == 2 * a[l] - 1) {
                    k = 0;
                    res++;
                }
                break;
            }
        } else if (a[l] < a[r]) {
            if (k >= 2 * a[l]) {
                k -= 2 * a[l];
                a[r] -= a[l];
                l++;
                res++;
            } else {
                if (k == 2 * a[l] - 1) {
                    k = 0;
                    res++;
                }
                break;
            }
        } else if (a[r] < a[l]) {
            if (k >= 2 * a[r]) {
                k -= 2 * a[r];
                a[l] -= a[r];
                r--;
                res++;
            } else {
                break;
            }
        }
    }
    debug(l, r, a[l], a[r], res, k);
    if (l == r) {
        if (k >= a[l]) {
            res++;
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
