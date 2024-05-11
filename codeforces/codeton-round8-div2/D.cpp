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
    int n, k; cin >> n >> k;
    vector a(n + 1, vector<int> (n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> a[i][j];
        }
    }

    if (n == 1) {
        if (k == 1) {
            cout << (a[0][0] >= 0 ? a[0][0] : 0) << endl;
        } else {
            int first = a[0][0] >= 0 ? a[0][0] : 0 << endl;
            int second = a[0][0] ^ first;
            cout << first << " " << second << endl;
        }
        return;
    }

    multiset<int> overall;
    multiset<pair<int, int>> all;
    all.insert({0, -2});
    all.insert({a[0][0], 0});
    overall.insert(0);
    for (int i = 0; i < n; i++) {
        overall.insert(a[0][i]);
        if (i >= 1) overall.insert(a[1][i]);
    }

    vector<int> p;
    p.push_back(a[0][1]);
    p.push_back(a[1][1]);

    debug(all, overall);
    for (int i = 2; i < n; i++) {

        vector<int> my_vals;
        for (int j = i; j < n; j++) {
            my_vals.push_back(a[i][j]);
        }
        sort(my_vals.rbegin(), my_vals.rend());

        int it = 0;
        for (auto val : my_vals) {
            auto itt = all.rbegin();
            while (itt != all.rend()) {
                overall.insert(val + itt->first);
                itt++;
                it++;
                if (it >= k) break;
            }
            if (it >= k) break;
        }

        debug(overall);
        vector<int> mx(n, INT_MIN);
        for (int j = i; j >= 0; j--) {
            mx[j] = max(mx[j], a[j][i]);
            if (j < n - 1) mx[j] = max(mx[j], mx[j + 1]);
        }

        debug(i, my_vals);
        debug(mx);
        debug(overall);
        debug(all);

        multiset<pair<int, int>> temp;
        for (auto [x, r] : all) temp.insert({r, x});

        vector<int> now;
        for (auto [r, x] : temp) if (r < n - 2) {
            now.push_back(mx[r + 2] + x);
        }

        for (auto u : p) all.insert({u, i - 1});
        p.clear();
        p = now;

        while ((int)overall.size() > k) overall.erase(overall.begin());
        while ((int)all.size() > k) all.erase(all.begin());
    }

    while (overall.size()) {
        cout << *overall.rbegin() << " ";
        overall.erase(--overall.end());
    }
    cout << endl;

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
