#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

map<int, int> best;

void solve() {
    int n; cin >> n;
    if (n == 3) cout << n << endl;
    else cout << 2 << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= 100; i++) {
        int bst = 0, who = -1;
        for (int j = 2; j <= i; j++) {
            int now = 0;
            for (int k = j; k <= i; k += j) {
                now += k;
            }
            if (now > bst) {
                bst = now;
                who = j;
            }
        }
        best[i] = who;
        // cout << i << " " << best[i] << endl;
    }

    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}