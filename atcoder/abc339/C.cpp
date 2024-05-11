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
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll L = -1, R = 1e18;
    while (R - L > 1) {
        ll M = (L + R) / 2;
        ll curr = M;
        bool db = 1;
        for (int i = 0; i < n; i++) {
            curr += a[i];
            if (curr < 0) db = 0;
        }
        if (db) R = M;
        else L = M;
    }
    for (int i = 0; i < n; i++) R += a[i];
    cout << R << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
