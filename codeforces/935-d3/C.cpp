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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = (c == '1');
    }
    vector<int> p(n + 1), s(n + 2);
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + (a[i] == 0);
    for (int i = n; i >= 1; i--) s[i] = s[i + 1] + (a[i] == 1);

    double best = 1e9;
    int res = 1e9;

    for (int i = 0; i <= n; i++) {
        int l = i;
        int r = n - i;
        int L = p[i];
        int R = s[i + 1];
        if (L >= (l + 1) / 2 && R >= (r + 1) / 2) {
            if (abs(((double)n / 2) - i) < best) {
                best = abs(((double)n / 2) - i);
                res = i;
            }
        }
    }

    cout << res << endl;
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
