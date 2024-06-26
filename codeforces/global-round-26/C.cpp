#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const ll MOD = (998244353LL);

ll add(ll a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll c = 0;

    vector<ll> mn(n + 1), mx(n + 1), dpmx(n + 1), dpmn(n + 1);
    dpmx[0] = 1;

    for (int i = 0; i < n; i++) {
        ll p1 = mx[i] + a[i];
        ll p2 = abs(mx[i] + a[i]);
        ll p3 = mn[i] + a[i];
        ll p4 = abs(mn[i] + a[i]);

        ll max_now = max({p1, p2, p3, p4});
        ll min_now = min({p1, p2, p3, p4});

        mx[i + 1] = max_now;
        mn[i + 1] = min_now;

        if (p1 == max_now) {
            dpmx[i + 1] = add(dpmx[i + 1], dpmx[i]);
        }
        if (p2 == max_now) {
            dpmx[i + 1] = add(dpmx[i + 1], dpmx[i]);
        }
        if (mn[i] != mx[i] && p3 == max_now) {
            dpmx[i + 1] = add(dpmx[i + 1], dpmn[i]);
        }
        if (mn[i] != mx[i] && p4 == max_now) {
            dpmx[i + 1] = add(dpmx[i + 1], dpmn[i]);
        }

        if (p1 == min_now) {
            dpmn[i + 1] = add(dpmn[i + 1], dpmx[i]);
        }
        if (p2 == min_now) {
            dpmn[i + 1] = add(dpmn[i + 1], dpmx[i]);
        }
        if (mn[i] != mx[i] && p3 == min_now) {
            dpmn[i + 1] = add(dpmn[i + 1], dpmn[i]);
        }
        if (mn[i] != mx[i] && p4 == min_now) {
            dpmn[i + 1] = add(dpmn[i + 1], dpmn[i]);
        }

        debug(p1, p2, p3, p4);
        debug(max_now, min_now);
        debug(i + 1, dpmx[i + 1], dpmn[i + 1]);

    }

    cout << dpmx[n] << endl;

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