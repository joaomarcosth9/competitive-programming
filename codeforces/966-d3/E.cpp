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
    int n, m, k;
    cin >> n >> m >> k;

    int w;
    cin >> w;

    vector<int> a(w);
    for (int &i : a)
        cin >> i;

    vector pref(n + 2, vector<int> (m + 2));

    auto update = [&] (int i, int j, int i2, int j2) {
        pref[i][j]++;
        pref[i][j2 + 1]--;
        pref[i2 + 1][j]--;
        pref[i2 + 1][j2 + 1]++;
    };

    for (int i = 1; i + k - 1 <= n; i++) {
        for (int j = 1; j + k - 1 <= m; j++) {
            update(i, j, i + k - 1, j + k - 1);
        }
    }

    priority_queue<int> pq;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            pq.push(pref[i][j]);
        }
    }

    assert((int)pq.size() >= w);

    ll res = 0;

    sort(begin(a), end(a));

    while (w--) {
        res += (ll)pq.top() * a[w];
        pq.pop();
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