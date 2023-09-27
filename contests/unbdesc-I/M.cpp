#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    long long x, y;
    cin >> x >> y;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    long long N = n;
    while (N < x || N < y) N <<= 1;
    long long ac = 0;
    while (N > n) {
        long long h = N >> 1;
        if (x <= h && y <= h) {
            // nada
        } else if (x > h && y <= h) {
            x -= h;
            ac += h;
        } else if (x <= h && y > h) {
            y -= h;
            ac += h;
        } else if (x > h && y > h) {
            x -= h;
            y -= h;
        }
        N >>= 1;
    }
    cout << 1ll * v[x][y] + ac << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
