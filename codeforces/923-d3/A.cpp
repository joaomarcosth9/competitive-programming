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
    int n; cin >> n;
    string s; cin >> s;
    int last = -1, first = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') last = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'B') first = i;
    }
    if (first != -1) cout << (last - first + 1) << endl;
    else cout << 0 << endl;
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
