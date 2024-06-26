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
    for (int &i : a) cin >> i;

    map<int, multiset<int>> m;

    for (int i = 0; i < n; i++) {
        m[a[i] >> 2].insert(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << *m[a[i] >> 2].begin() << " ";
        m[a[i] >> 2].erase(m[a[i] >> 2].begin());
    }
    cout << endl;
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
