#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n, c, d; cin >> n >> c >> d;
    vector<int> a(n * n);
    for (int &u : a) cin >> u;
    map<int, int> f;
    for (int &u : a) f[u]++;

    sort(a.begin(), a.end());

    vector b(n, vector<int> (n));

    b[0][0] = a[0];

    vector<int> g;
    g.push_back(b[0][0]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0) b[i][j] = b[i][j - 1] + d;
            else b[i][j] = b[i - 1][j] + c;
            g.push_back(b[i][j]);
        }
    }
    sort(g.begin(), g.end());

    return a == g;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
