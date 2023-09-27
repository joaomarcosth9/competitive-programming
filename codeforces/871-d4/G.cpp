#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define int long long
const int maxl = 2005;

int mat[maxl][maxl], pref[maxl][maxl], res[maxl][maxl];
pair<int, int> where[maxl * maxl];

void solve() {
    int u;
    cin >> u;
    auto [i, j] = where[u];
    cout << res[i][j] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int linha = 0;
    long long u = 1;
    for (int i = 0; i < maxl; i++) {
        for (int j = 0; j <= i; j++) {
            mat[i][j] = u * u;
            where[u] = {i, j};
            u++;
        }
    }
    for (int i = 1; i < maxl; i++) {
        for (int j = 0; j <= i; j++) {
            pref[i][j] = pref[i - 1][j] + mat[i - 1][j];
        }
    }
    res[0][0] = 1;
    for (int i = 1; i < maxl - 1; i++) {
        res[i][i] = res[i - 1][i - 1] + pref[i + 1][i];
        res[i][0] = pref[i + 1][0];
    }
    for (int i = 1; i < maxl; i++) {
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i - 1][j - 1] + pref[i + 1][j];
        }
    }
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
