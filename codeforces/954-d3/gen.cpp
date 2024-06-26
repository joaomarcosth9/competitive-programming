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
    int t = 100;
    cout << t << endl;
    for (int j = 0; j < t; j++) {
        int n = 10;
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << (char)('0' + rng() % 10);
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
