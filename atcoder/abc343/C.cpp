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
    for (ll i = 1; i * i * i <= n; i++) {
        ll x = i * i * i;
        string s = to_string(x);
        string t = s;
        reverse(t.begin(), t.end());
        if (s == t) {
            res = s;
        }
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
