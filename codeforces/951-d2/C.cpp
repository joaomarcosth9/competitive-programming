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
    ll L = 1;
    ll num = 0, deno = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        L = lcm(L, a[i]);
    }
    deno = L;
    for (int i = 0; i < n; i++) {
        num += (L / a[i]);
    }
    if (num >= deno) {
        cout << -1 << endl;
        return;
    }
    debug(L);
    for (int i = 0; i < n; i++) {
        cout << (L / a[i]) << " ";
    }
    cout << endl;
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