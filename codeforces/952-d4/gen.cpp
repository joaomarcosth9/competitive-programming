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

int uniform_int(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

void solve() {
    int n = 4, m = 15;
    int t = 10;
    cout << t << endl;
    for (int _ = 0; _ < t; _++) {
        cout << n << " " << m << endl;
        int i = n, j = m;
        vector<string> a(i, string(j, '.'));
        for (int ii = 0; ii < i; ii++) {
            for (int jj = 0; jj < j; jj++) {
                if (uniform_int(0, 2) == 0) {
                    a[ii][jj] = '#';
                }
            }
        }
        for (int ii = 0; ii < i; ii++) {
            for (int jj = 0; jj < j; jj++) {
                cout << a[ii][jj];
            }
            cout << endl;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
