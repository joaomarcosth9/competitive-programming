#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 2e3 + 5;
int n, t;

int mdiag, sdiag;
int visr[N], visc[N];

void solve() {
    cin >> n >> t;

    mdiag = sdiag = n;

    for (int i = 0; i < t; i++) {
        int x; cin >> x;
        int row = (x - 1) / n + 1, column = x % n;
        if (column == 0) column = n;
        visr[row]++;
        visc[column]++;
        if (row == column) mdiag--;
        if (row == n + 1 - column) sdiag--;
        if (visr[row] == n || visc[column] == n || mdiag == 0 || sdiag == 0) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
