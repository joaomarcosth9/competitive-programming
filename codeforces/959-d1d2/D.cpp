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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> res(n - 1);

    vector<int> is_rep(n, 1);

    for (int i = n - 1; i >= 1; i--) {
        vector<int> md(i, -1);
        for (int j = 0; j < n; j++) if (is_rep[j]) {
            if (md[a[j] % i] == -1) {
                md[a[j] % i] = j;
            } else {
                is_rep[j] = 0;
                res[i - 1] = {j + 1, md[a[j] % i] + 1};
                break;
            }
        }
    }

    cout << "YES" << endl;

    for (auto [u, v] : res) {
        cout << u << " " << v << endl;
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
