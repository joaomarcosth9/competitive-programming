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
    ll n; cin >> n;
    /* vector<ll> a = {7, 18, 21, 22, 23}; */
    /* debug(n, bin(n, 6)); */
    /* for (auto u : a) { */
    /*     debug(bin(u, 6)); */
    /* } */
    if (n == (n & -n)) {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }
    ll most = 0;
    vector<ll> res;
    res.push_back(0);
    for (int bit = 61; bit >= 0; bit--) {
        if (n & (1LL << bit)) {
            most |= (1LL << bit);
            ll other = (n ^ most);
            res.back() |= other;
            res.push_back(most);
        }
    }
    for (int i = 1; i < (int)res.size(); i++) {
        assert(res[i] > res[i - 1]);
        assert(res[i] | res[i - 1] == n);
    }
    cout << res.size() << endl;
    for (auto u : res) {
        cout << u << ' ';
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
