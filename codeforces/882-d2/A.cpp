#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 100;
int a[maxn], b[maxn];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        b[i] = abs(a[i] - a[i + 1]);
    }
    sort(b, b + n - 1);
    debug(vec(b, n - 1));
    cout << accumulate(b, b + n - k, 0ll) << '\n';
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
