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
ll res[N];

void solve() {
    int n; cin >> n;
    cout << res[n] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i < N; i++) {
        int now = 0;
        int j = i;
        while (j > 0) {
            now += j % 10;
            j /= 10;
        }
        res[i] = res[i - 1] + now;
    }

    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
