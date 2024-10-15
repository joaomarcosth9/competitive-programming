#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    vector<int> dp(2 * n + 2, -1e9);

    int both = 0, x = 0, y = 0;
    int both_neg = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == -1) {
                both_neg++;
            } else if (a[i] == 1) {
                both++;
            }
        } else {
            if (a[i] == 1) {
                x++;
            } else if (b[i] == 1) {
                y++;
            }
        }
    }

    while (both > 0) {
        if (x > y) swap(x, y);
        both--;
        x++;
    }

    while (both_neg > 0) {
        if (x > y) swap(x, y);
        both_neg--;
        y--;
    }

    cout << min(x, y) << endl;

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