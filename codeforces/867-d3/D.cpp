#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    } else if (n & 1) {
        cout << -1 << '\n';
        return;
    }

    auto f = [&](long long i) {
        if (i == 0) return n;
        if (i == n - 1) return 1ll;
        if (i & 1) {
            return n - i;
        } else {
            return i;
        }
    };

    for (int i = 0; i < n; i++) {
        cout << f(i) << " ";
    }
    cout << '\n';
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
