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
    int n;
    cin >> n;
    vector<int> used(n + 2);
    int x;
    cin >> x;

    used[x] = 1;

    bool ok = 1;

    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        if (!used[x + 1] && !used[x - 1]) {
            ok = 0;
        }
        used[x] = 1;
    }

    return ok;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        // cout << solve() << endl;
        cout << (solve() ? "Yes" : "No") << endl;
    }
}