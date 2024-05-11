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
    vector<set<pair<int, int>>> events(5001);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        events[l].insert({i, 1});
        events[r].insert({i, 2});
    }
    vector<int> res(n);
    set<int> active;
    for (int i = 1; i <= 5000; i++) {
        for (auto [j, t] : events[i]) {
            if (t == 1) {
                active.insert(j);
            }
        }
        if (active.size()) {
            res[*active.begin()] = i;
            active.erase(active.begin());
        }
        for (auto [j, t] : events[i]) {
            if (t == 2) {
                active.erase(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
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
