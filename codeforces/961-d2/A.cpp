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
    int n, k; cin >> n >> k;
    if (k == 0) return 0;
    if (k <= n) {
        return 1;
    } else {
        k -= n;
        int res = 1;
        int cur = n - 1;
        while (k > cur * 2) {
            res += 2;
            k -= cur * 2;
            cur--;
        }
        // k <= cur * 2
        if (k <= cur) {
            res++;
        } else {
            res += 2;
        }
        return res;
    }
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