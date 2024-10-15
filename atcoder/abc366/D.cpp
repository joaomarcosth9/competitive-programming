#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 105;

int a[N][N][N];
ll pref[N][N][N];

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> a[i][j][k];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                pref[i][j][k] = a[i][j][k];
                pref[i][j][k] += pref[i - 1][j][k] + pref[i][j - 1][k] + pref[i][j][k - 1];
                pref[i][j][k] -= pref[i - 1][j - 1][k] + pref[i - 1][j][k - 1] + pref[i][j - 1][k - 1];
                pref[i][j][k] += pref[i - 1][j - 1][k - 1];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        ll res = pref[rx][ry][rz];
        res -= pref[lx - 1][ry][rz] + pref[rx][ly - 1][rz] + pref[rx][ry][lz - 1];
        res += pref[lx - 1][ly - 1][rz] + pref[lx - 1][ry][lz - 1] + pref[rx][ly - 1][lz - 1];
        res -= pref[lx - 1][ly - 1][lz - 1];

        cout << res << endl;
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}