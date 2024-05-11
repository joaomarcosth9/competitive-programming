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
    vector<ll> a(n + 2), b(n + 2), p(n + 2), s(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        s[i] = s[i + 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        res = max(res, p[i - 1] + b[i] + s[i + 1]);
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
