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
    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // pra cada subarray, qnts caras do b dao match?

    map<int, int> need, f;

    for (auto u : b) {
        f[u]++;
        need[u]++;
    }

    map<int, set<int>> where;

    int res = 0, cur = 0;

    for (int i = m - 1; i >= 0; i--) {
        if (need[a[i]] > 0) {
            where[a[i]].insert(i);
            need[a[i]]--;
            cur++;
        }
    }

    res += cur >= k;

    for (int i = m; i < n; i++) {
        // + a[i], -a[i - m]

        if (where[a[i - m]].count(i - m)) {
            where[a[i - m]].erase(i - m);
            need[a[i - m]]++;
            cur--;
        }

        if (f[a[i]] > 0) {
            if (need[a[i]] > 0) {
                where[a[i]].insert(i);
                need[a[i]]--;
                cur++;
            } else {
                where[a[i]].erase(where[a[i]].begin());
                where[a[i]].insert(i);
            }
        }

        res += cur >= k;

    }

    cout << res << endl;

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
