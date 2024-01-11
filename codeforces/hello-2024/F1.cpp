#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 500500, Q = 500500;
int n, q;
ll c[N], a[N], b[N], oa[N];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i];
    }

    ll res = 0;

    memcpy(oa, a, sizeof(int) * n);

    while (q--) {
        int idx, va, vb; ll vc;
        cin >> idx >> va >> vb >> vc;
        debug(idx, va, vb, vc);
        idx--;

        debug(a[idx], b[idx]);
        
        a[idx] = va;
        b[idx] = vb;

        debug(a[idx], b[idx]);

        res = 0;

        ll sobra = 0;

        for (int i = 0; i < n; i++) {
            debug(a[i], b[i]);
            debug(a[i] + sobra, b[i]);

            res += min(a[i] + sobra, b[i]);
            if (i < n - 1) sobra = max(0ll, a[i] + sobra - b[i]);
        }

        cout << res << endl;
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
