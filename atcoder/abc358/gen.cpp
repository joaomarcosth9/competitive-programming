#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n = 4, m = 4, k = 10;
    cout << n << ' ' << m << ' ' << k << endl;
    int ii = (rng() % n) + 1, jj = (rng() % m) + 1;
    cout << ii << ' ' << jj << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (rng() % 10) + 1 << ' ';
        }
        cout << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
