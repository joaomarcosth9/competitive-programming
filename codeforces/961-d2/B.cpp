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

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());

    vector<pair<int, int>> b = {a[0]};

    for (int i = 1; i < n; i++) {
        if (a[i].first == b.back().first) {
            b.back().second += a[i].second;
        } else {
            b.push_back(a[i]);
        }
    }

    n = (int)b.size();
    a = b;

    debug(n, a);

    ll res = 0;

    for (int i = 0; i < n; i++) {
        auto [v1, cnt1] = a[i];
        int qnt = m / v1;
        int now = min(qnt, cnt1) * v1;
        res = max(res, now);
    }

    for (int i = 1; i < n; i++) {
        auto [v1, cnt1] = a[i - 1];
        auto [v2, cnt2] = a[i];

        if (abs(v1 - v2) > 1) {
            continue;
        }

        int k1 = min(cnt1, m / v1); // uso tudo possivel do v1

        int has = m - k1 * v1;

        int k2 = min(cnt2, has / v2); // uso tudo possivel do v2

        int now = k1 * v1 + k2 * v2;

        has = m - now;

        // agora pra cada v1, eu quero botar v2 enquanto nao passa de m
        // eu tenho (cnt2 - k2) caras pra por, tenho k1 caras que posso tirar, e posso por no maximo has 

        res = max(res, now + min({has, (cnt2 - k2), k1}));
    }

    assert(res <= m);
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
