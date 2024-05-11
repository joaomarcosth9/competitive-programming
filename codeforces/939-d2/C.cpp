#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = max(i, j) + 1;
            sum += a[i][j];
        }
    }

    cout << sum << " " << 2 * n - 1 << endl;
    for (int i = 0; i < n; i++) {
        cout << 1 << " " << n - i << " ";
        for (int j = 0; j < n; j++) cout << j + 1 << " ";
        cout << endl;
        if (n - i > 1) {
            cout << 2 << " " << n - i - 1 << " ";
            for (int j = 0; j < n; j++) cout << j + 1 << " ";
            cout << endl;
        }
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
