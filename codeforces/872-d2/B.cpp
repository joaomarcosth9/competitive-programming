#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif

void solve() {
    long long res1 = 0, res2 = 0;
    int n, m;
    cin >> n >> m;
    vector<long long> v(n * m);
    for (int i = 0; i < (n * m); i++) {
        cin >> v[i];
    }
    sort(begin(v), end(v));
    int k = v.size();
    if (m > n) swap(n, m);
    res1 += (v[k - 1] - v[0]) * (n - 1); // maior diferenca
    res1 += (v[k - 2] - v[0]) * (m - 1);
    res1 += (v[k - 1] - v[0]) * (n - 1) * (m - 1);
    res2 += (v[k - 1] - v[0]) * (n - 1);
    res2 += (v[k - 1] - v[1]) * (m - 1);
    res2 += (v[k - 1] - v[0]) * (n - 1) * (m - 1);
    debug(res1, res2);
    cout << max(res1, res2) << '\n';
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
