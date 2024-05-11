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
    int h, m;
    char c;
    cin >> h >> c >> m;
    string s;
    if (h == 0) {
        s = "AM";
        h = 12;
    } else {
        if (h <= 11) {
            s = "AM";
        } else {
            s = "PM";
            if (h != 12) h %= 12;
        }
    }
    if (h <= 9) cout << "0";
    cout << h << ":";
    if (m <= 9) cout << "0";
    cout << m << " " << s << endl;
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
