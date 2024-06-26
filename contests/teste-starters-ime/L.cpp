#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct basis {
    ll rep[63];
    basis() {
        memset(rep, 0, sizeof rep);
    }
    void insert(ll x) {
        for (int b = 62; b >= 0; b--) {
            if (x & (1LL << b)) {
                if (rep[b] == 0) {
                    rep[b] = x;
                    return;
                } else {
                    x ^= rep[b];
                }
            }
        }
    }
    ll query() {
        ll res = 0;
        for (int b = 62; b >= 0; b--) {
            if (~res & (1LL << b)) {
                if (rep[b] != 0) {
                    res ^= rep[b];
                }
            }
        }
        return res;
    }
} b;

int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        b.insert(x);
        cout << b.query() << " ";
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}