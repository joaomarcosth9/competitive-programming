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
    string res;
    while (n) {
        if (n & 1) {
            res += 'A';
            n--;
        } else {
            res += 'B';
            n >>= 1;
        }
    }
    reverse(begin(res), end(res));
    cout << res << endl;
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
