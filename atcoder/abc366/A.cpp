#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a > (n / 2) || b > (n / 2)) {
        return 1;
    }
    return 0;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // solve();
    // cout << solve() << endl;
    cout << (solve() ? "Yes" : "No") << endl;
}