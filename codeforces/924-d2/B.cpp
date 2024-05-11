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
    for (int &c : a) cin >> c;
    sort(begin(a), end(a));
    a.erase(unique(begin(a), end(a)), end(a));
    int N = n;
    n = (int)a.size();
    int res = 0;
    int j = 0;
    debug(a);
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] - a[i] <= (N - 1)) j++;
        debug(i, j);
        res = max(res, j - i);
    }
    cout << res << endl;
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
