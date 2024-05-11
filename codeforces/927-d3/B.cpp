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
    vector<int> a(n);
    ll L = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        L = lcm(a[i], L);
    }
    ll year = a[0];
    for (int i = 1; i < n; i++) {
        ll m = year % a[i];
        if (m == 0) year += a[i];
        else year += a[i] - m;
    }
    cout << year << endl;
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
