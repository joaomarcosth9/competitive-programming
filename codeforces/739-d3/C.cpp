#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    long long k;
    cin >> k;
    long long i = 1, j = 1;
    long long b = 1;
    while (b * b < k) b++;
    db(k, b);
    db(i, j);
    if (k < (b * b) - ((b * b - (b - 1) * (b - 1) - 1) >> 1)) {
        i = (k - (b - 1) * (b - 1));
        j = b;
    } else {
        i = b;
        j = (b * b - k + 1);
    }
    cout << i << " " << j << endl;
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
