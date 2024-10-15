#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, (int)a[i].size());
    }
    vector<string> b(m);
    for (int it = m - 1; it >= 0; it--) {
        b[it].resize(101, '0');
    }

    for (int i = 0; i < n; i++) {
        int pos = n - 1 - i;
        for (int j = 0; j < (int)a[i].size(); j++) {
            b[j][pos] = a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        bool has_letter = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (b[i][j] != '0') {
                has_letter = 1;
            }
            if (b[i][j] == '0' && has_letter) {
                b[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] == '0') {
                continue;
            } else {
                cout << b[i][j];
            }
        }
        cout << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}