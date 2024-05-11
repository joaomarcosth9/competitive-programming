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

int t = 0;

void solve() {
    t++;
    int n; cin >> n;

    vector<ll> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i];
        if (i > 0) p[i] += p[i - 1];
    }

    map<ll, int> f;
    int mx = 0;
    ll who = -1;
    ll res = 0;
    ll z = 0;

    debug(a);
    debug(p);
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] == 0) z++;
        f[p[i]]++;
        if (f[p[i]] > mx) {
            mx = f[p[i]];
        }
        if (a[i] == 0) {
            res += mx;
            mx = 0;
            z = 0;
            f.clear();
        }
    }

    cout << res + z << endl;
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
