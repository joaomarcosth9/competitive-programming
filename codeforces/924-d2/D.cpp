#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;

int solve(int c, int k) {
    if (k >= c) {
        return (c * (c - 1)) / 2;;
    }
    int y1 = c / k, y2 = (c + k - 1) / k;
    int q2 = c % k;
    int q1 = k - q2;
    debug(c, k);
    debug(y1, y2, q1, q2);
    return ((q1 * y1) * (y1 * (q1 - 1) + y2 * q2) + 
            (q2 * y2) * (y2 * (q2 - 1) + y1 * q1)) / 2;
}

void solve() {
    int n, b, x; cin >> n >> b >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(begin(c), end(c));
    vector<int> res(c.back() + 1);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= c[i]; j++) {
            res[j] += solve(c[i], j) * b;
            debug(c[i], j, solve(c[i], j), res[j]);
        }
    }

    int ans = 0;
    int l = 0, oth = 0;
    debug(c);
    for (int i = 1; i < (int)res.size(); i++) {
        while (l < n && c[l] < i) {
            oth += solve(c[l], i);
            l++;
        }
        debug(i, l, oth);
        ans = max(ans, (res[i] + (oth * b)) - (i - 1) * x);
    }
    cout << ans << endl;
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
