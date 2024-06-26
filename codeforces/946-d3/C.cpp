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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<tuple<int, int, int>, int> f;
    map<pair<int, int>, int> f1, f2, f3;
    for (int i = 0; i < n - 2; i++) {
        tuple<int, int, int> now = {a[i], a[i + 1], a[i + 2]};
        f[now]++;
        pair<int, int> now1 = {a[i], a[i + 1]};
        f1[now1]++;
        pair<int, int> now2 = {a[i + 1], a[i + 2]};
        f2[now2]++;
        pair<int, int> now3 = {a[i], a[i + 2]};
        f3[now3]++;
    }
    ll res = 0;
    for (int i = 0; i < n - 2; i++) {
        tuple<int, int, int> now = {a[i], a[i + 1], a[i + 2]};
        pair<int, int> now1 = {a[i], a[i + 1]};
        pair<int, int> now2 = {a[i + 1], a[i + 2]};
        pair<int, int> now3 = {a[i], a[i + 2]};

        res += f1[now1] - f[now];
        res += f2[now2] - f[now];
        res += f3[now3] - f[now];
    }
    cout << res / 2 << endl;
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
