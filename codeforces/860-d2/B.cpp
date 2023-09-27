#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int nn;
        cin >> nn;
        v[i].resize(nn);
        for (int j = 0; j < nn; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> winners(n);
    reverse(begin(v), end(v));
    map<int, int> vis;
    for (int i = 0; i < n; i++) {
        int db = 0;
        for (int c : v[i]) {
            if (!vis[c]) {
                winners[n - i - 1] = c;
                db = 1;
                break;
            }
        }
        if (!db) {
            cout << -1 << endl;
            return;
        }
        for (int c : v[i]) {
            vis[c] = 1;
        }
    }
    for (int c : winners) {
        cout << c << " ";
    }
    cout << endl;
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
