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
    string s, t; cin >> s >> t;
    int zeroum = 0, umzero = 0;
    for (int i = 0; i < n; i++) if (s[i] != t[i]) {
        if (s[i] == '0') zeroum++;
        else umzero++;
    }
    cout << max(zeroum, umzero) << endl;
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
