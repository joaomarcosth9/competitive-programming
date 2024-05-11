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
ll pref[N];

void solve() {
    int n; cin >> n;
    cout << pref[n] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    pref[0] = 0;
    for (int i = 1; i < N; i++) {
        int j = i;
        int sum = 0;
        while (j > 0) {
            sum += j % 10;
            j /= 10;
        }
        pref[i] = pref[i - 1] + sum;
    }
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
