#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> m(70);
    m[0] = 1;

    __int128_t curr = 1;

    while (curr <= n) {
        if ((curr % b) == (n % b)) return true;
        if (a == 1) return false;
        curr *= a;
    }

    return false;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
