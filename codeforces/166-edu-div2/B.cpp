#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n + 1);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    int who = 2e9;
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            if (b.back() <= a[i] && b.back() >= b[i]) {
                who = b.back();
            }
        } else if (a[i] < b[i]) {
            if (b.back() >= a[i] && b.back() <= b[i]) {
                who = b.back();
            }
        }
        if (abs(a[i] - b.back()) < abs(who - b.back())) {
            who = a[i];
        }
        if (abs(b[i] - b.back()) < abs(who - b.back())) {
            who = b[i];
        }
        res += abs(a[i] - b[i]);
    }
    cout << res + abs(who - b.back()) << endl;
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
