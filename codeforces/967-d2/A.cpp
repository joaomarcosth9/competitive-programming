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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> f;
    for (int &i : a) {
        cin >> i;
        f[i]++;
    }
    int mx = 0;
    for (auto [k, v] : f) {
        mx = max(mx, v);
    }
    cout << n - mx << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}