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
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    for (int i = 0; i < n - 2; i++) {
        if (a[i] < 0) return 0;
        a[i + 2] -= a[i];
        a[i + 1] -= 2 * a[i];
    }
    return a[n - 2] == 0 && a[n - 1] == 0;
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
