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
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        int lowest = -abs(x);
        y -= abs(x) - 1;
        cout << (lowest <= y ? "YES" : "NO") << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}