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
    int x = 0, y = 0;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) a[i] = INT_MAX;
        if (b[i] == -1) b[i] = INT_MAX;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        (a[i] < b[i] ? x : y)++;
    }
    cout << (x == y ? "Tie" : (x < y ? "Alfredo" : "Saboya")) << endl;
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