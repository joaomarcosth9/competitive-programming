#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e5 + 5;
int n, q, a[N];
ll pref[N];

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 1e4
        pref[i + 1] = pref[i] + a[i];
    }

    auto query = [&] (int l, int r, ll u) {
        ll sum = pref[r + 1] - pref[l];
        ll ret = sum * u;
        ret -= sum * (sum - 1) / 2;
        return ret;
    };

    cin >> q;
    debug(n, q);

    while (q--) {
        int l; ll u; cin >> l >> u;
        l--;
        ll sum = 0;
        int L = l, R = n - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            int mid2 = mid + 1;
            assert(mid2 <= R);
            if (query(l, mid, u) <= query(l, mid2, u)) {
                L = mid2;
            } else {
                R = mid;
            }
        }
        ll best = LLONG_MIN;
        int who = -1;
        for (int i = max(l, L - 10); i <= min(n - 1, L + 10); i++) {
            ll now = query(l, i, u);
            if (now > best) {
                best = now;
                who = i;
            }
        }
        cout << who + 1 << " ";
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
