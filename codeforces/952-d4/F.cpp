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
    int h, n; cin >> h >> n;
    vector<int> a(n), c(n);
    for (int &x : a) {
        cin >> x;
    }
    for (int &x : c) {
        cin >> x;
    }

    map<int, int> compr;
    for (int i = 0; i < n; i++) {
        compr[c[i]] += a[i];
    }

    int total_damage = 0;

    map<int, vector<pair<int, int>>> attacks;

    for (auto &[k, v] : compr) {
        total_damage += v;
        attacks[k + 1].push_back({k, v});
    }
    debug(attacks);

    if (total_damage >= h) {
        cout << 1 << endl;
        return;
    }

    h -= total_damage;

    auto it = attacks.begin();

    int res = 0;

    while (h > 0) {
        auto [time_now, all] = *it;
        debug(time_now, all);
        res = time_now;
        for (auto each : all) {
            auto [cool_down, damage] = each;
            h -= damage;
            attacks[time_now + cool_down].push_back(each);
        }
        it = attacks.erase(it);
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