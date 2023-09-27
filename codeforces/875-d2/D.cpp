#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll res = 0;

    vector<int> a(n), b(n);
    map<pair<int, int>, int> f;
    vector<map<int, int>> m(2 * n + 1);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (int i = 0; i < n; i++) {
        f[make_pair(a[i], b[i])] = 1;
        m[a[i]][b[i]]++;
    }

    int sq = 1;
    while ((sq + 1) * (sq + 1) <= 2 * n) {
        sq++;
    }
    debug(n, sq);

    for (int i = 1; i <= sq; i++) {
        int val = i * i;
        debug(i);
        for (auto [k, v] : m[i]) {
            int need = val - k;
            auto u = m[i].find(need);
            if (need <= 0 || u == m[i].end()) continue;
            debug(need, k);
            if (need == k) {
                res += 1ll * v * v - v;
            } else {
                res += 1ll * v * u->second;
            }
        }
    }

    res /= 2;

    for (int i = 1; i <= n; i++) {
        // a[i] * a[j] <= 2 * n
        for (int j = 1; j <= min(i - 1, sq); j++) {
            int val = i * j;
            for (auto [k, v] : m[i]) {
                int need = val - k;
                auto u = m[j].find(need);
                if (need <= 0 || u == m[j].end()) continue;
                debug(need, k);
                res += 1ll * v * u->second;
            }
        }
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
