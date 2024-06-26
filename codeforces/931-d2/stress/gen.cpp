#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    cout << 1 << endl;
    cout << 20 << endl;
    for (int i = 0; i < 20; i++) {
        char moves[] = {'N', 'S', 'E', 'W'};
        cout << moves[rng() % 4];
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
