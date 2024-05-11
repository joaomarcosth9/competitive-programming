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
    vector<int> a(n);
    for (int &i : a) cin >> i;

    if (n == 1) {
        if (a[0] >= 1) {
            cout << a[0] << " 0" << endl;
        } else {
            cout << 1 << " " << 1 << endl;
            cout << 1 << " " << 1 << endl;
        }
        return;
    }

    ll best = 0;
    vector<pair<int, int>> ops;

    for (int i = 0; i < (1 << (n - 1)); i++) {
        vector<int> m(n);
        m[0] = 1;
        for (int j = 0; j < n - 1; j++) {
            if (i & (1 << j)) m[j + 1] = 1;
        }
        vector<int> now = a;
        vector<pair<int, int>> nowops;

        debug(now);
        debug(m);
        for (int j = 0; j < n; j++) {
            assert(m[j]);

            int nxt = n;
            for (int k = j + 1; k < n; k++) if (m[k]) {
                nxt = k;
                break;
            }

            ll rgsum = 0;
            for (int k = j; k < nxt; k++) {
                rgsum += now[k];
            }

            if (rgsum < (ll)(nxt - j) * (nxt - j)) {
                for (int k = j; k < nxt; k++) {
                    if (now[k] != 0) {
                        nowops.push_back({k, k});
                    }
                }
                for (int k = j; k < nxt; k++) {
                    nowops.push_back({j, k});
                }
                nowops.push_back({j, nxt - 1});
                for (int k = j; k < nxt; k++) {
                    now[k] = nxt - j;
                }
            }

            j = nxt - 1;
        }

        ll res = accumulate(now.begin(), now.end(), 0ll);
        debug(now, res);
        if (res > best) {
            best = res;
            ops = nowops;
        }
    }

    cout << best << " " << ops.size() << endl;
    for (auto [l, r] : ops) {
        cout << l + 1 << " " << r + 1 << endl;
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
