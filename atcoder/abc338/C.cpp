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
    vector<int> q(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll> now(n);
    ll res = 0;
    for (int i = 0; i <= int(1e6); i++) {

        int L = 0, R = int(1e6);
        ll ans = 0;
        while (L <= R) {
            int mid = (L + R) / 2;
            vector<ll> cur(n);
            for (int j = 0; j < n; j++) cur[j] = (ll)b[j] * mid;
            bool db = 1;
            for (int j = 0; j < n; j++) {
                db &= cur[j] + now[j] <= q[j];
            }
            if (db) {
                if (mid >= 1e4) {
                    debug(q);
                    debug(cur);
                    debug(now);
                }
                L = mid + 1;
                ans = mid;
            } else R = mid - 1;
        }
        res = max(res, i + ans);

        for (int j = 0; j < n; j++) now[j] += a[j];
        bool can = 1;
        for (int j = 0; j < n; j++) if (now[j] > q[j]) can = 0;
        if (!can) break;
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
