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
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    bool ok = n <= 2;
    if (ok && n == 2) {
        sort(begin(a), end(a));
        if (a[0] == a[1] - 1) ok = 0;
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