#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

typedef long long ll;

const int maxn = 1e5 + 5;
ll a[maxn], b[maxn];

void solve() {
    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    ll l = 0, r = 2e18;

    ll res = (ll)2e18 + 1;
    debug(l, r, res);
    while (l <= r) {
        ll mid = (l + r) >> 1;

        ll kpres = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) continue;
            kpres += (mid - a[i]) / b[i];
            kpres++;
            if (kpres >= k) break;
        }

        if (kpres >= k) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        debug(l, r);
    }
    assert(res != ((ll)2e18 + 1));

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
