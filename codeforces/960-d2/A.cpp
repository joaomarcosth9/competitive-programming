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
    int n; cin >> n;
    map<int, int> mx;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mx[x]++;
    }
    auto it = mx.rbegin();
    while (it != mx.rend()) {
        if (it->second & 1) return true;
        it++;
    }
    return false;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        // cout << solve() << endl;
        cout << (solve() ? "Yes" : "No") << endl;
    }
}