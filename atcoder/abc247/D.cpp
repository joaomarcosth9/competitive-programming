#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAX = 20;

void solve() {
    int q; cin >> q;

    deque<pair<ll, ll>> dq;

    for (int qq = 0; qq < q; qq++) {
        int t; cin >> t;
        if (t == 1) {
            ll x, c; cin >> x >> c;
            dq.push_back({x, c});
        } else {
            ll res = 0;

            ll qt; cin >> qt;
            while (dq.size() && qt > 0) {
                auto [x, c] = dq.front();
                if (qt >= c) {
                    res += x * c;
                    qt -= c;
                    dq.pop_front();
                } else {
                    res += x * qt;
                    dq.front().second -= qt;
                    qt = 0;
                }
            }

            cout << res << endl;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
