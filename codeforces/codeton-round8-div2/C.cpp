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
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(x);
    int res = x - 2;
    for (int i = 0; i < x; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    a.push_back(a[0]);
    vector<int> even, odd;

    for (int i = 0; i < x; i++) {
        int now = a[i];
        int nxt = a[(i + 1) % x];
        if (nxt < now) nxt += n;
        if (nxt - now == 2) res++;
        if (nxt - now <= 2) continue;
        if ((nxt - now) & 1) odd.push_back(nxt - now);
        else even.push_back(nxt - now);
    }
    debug(res);

    sort(even.begin(), even.end());

    debug(even);
    debug(odd);

    for (auto u : even) {
        int add = u - 1;
        int need = (u - 1) / 2;
        if (y >= need) y -= need, res += add;
        else odd.push_back(u - 1);
    }

    sort(odd.begin(), odd.end());

    for (auto u : odd) {
        int max_add = u - 1;
        int need = (u - 1) / 2;
        if (y >= need) y -= need, res += max_add;
        else {
            res += y * 2;
            y = 0;
            break;
        }
    }

    cout << res << endl;
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
