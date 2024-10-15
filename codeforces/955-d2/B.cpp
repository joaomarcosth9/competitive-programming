#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

pair<ll, ll> next_y(ll x, ll y) {
    if (x % y == 0) {
        return {x + y, y};
    }
    ll r = x % y;
    ll last = x - r;
    ll next = last + y;
    return {next, next - x};
}

ll solve() {
    ll x, y, k; cin >> x >> y >> k;
    while (x != 1 && k > 0) {
        auto [next, ops] = next_y(x, y);
        if (ops > k) {
            x += k;
            k = 0;
        } else {
            x = next;
            assert(x % y == 0);
            while (x % y == 0) {
                x /= y;
            }
            k -= ops;
        }
    }
    if (k == 0) return x;
    assert(x == 1);
    k %= (y - 1);
    return x + k;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}