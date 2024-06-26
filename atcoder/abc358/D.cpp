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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    debug(a);
    debug(b);

    multiset<int> sa(a.begin(), a.end());

    sort(b.begin(), b.end());

    int res = 0;

    for (int i = 0; i < m; i++) {
        auto now = sa.lower_bound(b[i]);
        if (now == sa.end()) {
            cout << -1 << endl;
            return;
        }
        res += *now;
        sa.erase(now);
    }

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}