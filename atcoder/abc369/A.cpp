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
    int a, b;
    cin >> a >> b;
    int res = 0;
    if (a != b) {
        res += 2;
        if (abs(a - b) % 2 == 0) {
            res++;
        }
    } else {
        res++;
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}