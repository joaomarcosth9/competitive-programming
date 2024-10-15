#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 2e5 + 5;
ll res[N], pref[N];

void solve() {
    int l, r;
    cin >> l >> r;

    ll mn = res[l];

    cout << (pref[r] - pref[l - 1]) + mn << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    for (int i = 0; i < N; i++) {
        int j = i, cur = 0;
        while (j > 0) {
            cur++;
            j /= 3;
        }
        res[i] = cur;
        if (i > 0) {
            pref[i] = pref[i - 1] + res[i];
        } else {
            pref[i] = res[i];
        }
    }
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}