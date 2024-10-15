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

    ll lim = 0;

    vector<vector<int>> all(3, vector<int> (n));
    for (int i = 0; i < 3; i++) {
        auto &a = all[i];
        lim = 0;
        for (int &j : a) {
            cin >> j;
            lim += j;
        }
    }

    lim = (lim + 2) / 3;

    debug(lim);

    vector<int> perm = {0, 1, 2};

    do {
        auto a = all[perm[0]];
        auto b = all[perm[1]];
        auto c = all[perm[2]];

        debug(a, b, c);

        ll tot_a = 0, tot_b = 0, tot_c = 0;

        vector<pair<int, pair<int, int>>> res;

        int last_i = -1;
        for (int i = last_i + 1; i < n; i++) {
            tot_a += a[i];
            if (tot_a >= lim) {
                res.push_back({perm[0], {last_i + 2, i + 1}});
                last_i = i;
                break;
            }
        }
        debug(tot_a);
        debug(res);
        if (tot_a < lim) continue;
        for (int i = last_i + 1; i < n; i++) {
            tot_b += b[i];
            if (tot_b >= lim) {
                res.push_back({perm[1], {last_i + 2, i + 1}});
                last_i = i;
                break;
            }
        }
        debug(tot_b);
        debug(res);
        if (tot_b < lim) continue;
        for (int i = last_i + 1; i < n; i++) {
            tot_c += c[i];
            if (tot_c >= lim) {
                res.push_back({perm[2], {last_i + 2, i + 1}});
                last_i = i;
                break;
            }
        }
        debug(tot_c);
        debug(res);
        if (tot_c < lim) continue;
        assert(res.size() == 3);
        sort(res.begin(), res.end());
        for (auto [u, v] : res) {
            cout << v.first << " " << v.second << " ";
        }
        cout << endl;
        return;
    } while (next_permutation(perm.begin(), perm.end()));

    cout << -1 << endl;
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