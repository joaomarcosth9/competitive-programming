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
    ll n, m; cin >> n >> m;
    int NN = n;
    vector<int> res;

    debug(bin(n, 63));
    debug(bin(m, 63));

    for (int i = 0; i < 63; i++) {
        int N = (n >> i) & 1;
        int M = (m >> i) & 1;
        if (N <= M) continue;
        ll x = 1ll << i;

        if (N > M) {
            for (int j = i - 1; j >= 0; j--) {
                int N2 = (n >> j) & 1;
                int M2 = (m >> j) & 1;
                if (N2 != M2) {
                    x |= 1ll << j;
                }
            }
        }

        debug(i, bin(x, 63));
        debug(i, bin(n, 63));
        debug(i, bin(m, 63));

        if (x > n) {
            cout << -1 << endl;
            return;
        }

        res.push_back(x);
        n ^= x;
    }

    if (n == m) {
        cout << res.size() << endl;
        cout << NN << " ";
        for (auto x : res) {
            debug(bin(x, 63));
            cout << (NN ^= x) << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

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
