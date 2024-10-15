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
    int used = 0;

    vector<int> sq = {1, 2, 2, 3, 1, 4, 4, 3};

    if (n >= 10) {
        sq.clear();
        sq = {1, 2, 3, 4};
    }

    int m = (int)sq.size();

    vector<int> c(n + 1);
    vector<int> vis(5);

    int it = 0;

    for (int i = 1; i <= n; i++) {
        c[i] = sq[it];
        if (!vis[c[i]]) {
            used++;
        }
        vis[c[i]] = 1;
        it = (it + 1) % m;
    }

    cout << used << endl;
    for (int i = 1; i <= n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

}

int32_t main() {
    // cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
