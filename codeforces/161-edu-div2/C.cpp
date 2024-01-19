#include "bits/stdc++.h"
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
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> L(n), R(n);

    L[0] = 0;
    R[0] = 1;
    R[n - 1] = 0;
    L[n - 1] = 1;

    for (int i = 1; i < n - 1; i++) {
        if (a[i] - a[i - 1] < a[i + 1] - a[i]) {
            L[i] = 1;
            R[i] = a[i + 1] - a[i];
        } else {
            R[i] = 1;
            L[i] = a[i] - a[i - 1];
        }
    }

    vector<ll> suffL(n + 1), prefR(n + 1);

    for (int i = 0; i < n; i++) {
        prefR[i + 1] = prefR[i] + R[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suffL[i] = suffL[i + 1] + L[i];
    }

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        if (x < y) {
            debug("1");
            cout << prefR[y - 1] - prefR[x - 1] << endl;
        } else {
            debug("2");
            cout << suffL[y] - suffL[x] << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
