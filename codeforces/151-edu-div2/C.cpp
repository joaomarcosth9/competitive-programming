#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> v(n);
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;
    vector<map<int, int>> next(n + 1);
    for (int i = n; i >= 0; i--) {
        for (int j = '0'; j <= '9'; j++) {
            if (i == n) {
                next[i][j] = -1;
            } else {
                if (s[i] == j) {
                    next[i][j] = i;
                } else {
                    next[i][j] = next[i + 1][j];
                }
            }
        }
    }
    int where = 0;
    for (int i = 0; i < m; i++) {
        int lo = l[i], hi = r[i];
        int prox = INT_MIN;
        for (int j = lo; j <= hi; j++) {
            int nxt = next[where][j];
            if (nxt == -1) {
                cout << "YES" << '\n';
                return;
            }
            prox = max(prox, nxt);
        }
        where = prox + 1;
    }
    cout << "NO" << '\n';
    debug(v);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
