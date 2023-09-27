#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int _xor = 0;
    for (int i = 0; i < n; i++) {
        _xor ^= v[i];
    }
    db(n, v);
    db(bin(_xor));
    if (n & 1) {
        cout << _xor << endl;
    } else {
        cout << (_xor ? -1 : 0) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
