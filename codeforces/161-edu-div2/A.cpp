#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n; cin >> n;
    string a, b, c; cin >> a >> b >> c;
    bool db = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            db |= c[i] != a[i];
        } else {
            if (a[i] != c[i] && b[i] != c[i]) db = 1;
        }
    }
    return db;
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
