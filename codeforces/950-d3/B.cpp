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
    int n, f, k; cin >> n >> f >> k;
    f--;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    bool can_be_removed = 0, can_be_kept = 0;
    int cnt_greater = 0, cnt_eq = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > a[f]) {
            cnt_greater++;
        } else if (a[i] == a[f]) {
            cnt_eq++;
        }
    }

    int l_most = cnt_greater + 1;
    int r_most = cnt_greater + cnt_eq;

    if (l_most <= k) can_be_removed = 1;
    if (r_most > k) can_be_kept = 1;

    if (can_be_kept && can_be_removed) {
        cout << "MAYBE" << endl;
    } else if (can_be_kept) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

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