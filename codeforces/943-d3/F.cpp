#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 3e5 + 5;
ll a[N], p[N], s[N], ps[N], ss[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n + 3; i++) a[i] = p[i] = s[i] = ps[i] = ss[i] = 0;
    int q; cin >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i + 1] = p[i] ^ a[i];
        ps[i + 1] = ps[i] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        s[i] = s[i + 1] ^ a[i - 1];
        ss[i] = ss[i + 1] + a[i - 1];
    }

    map<int, set<int>> idxp, idxs;

    for (int i = 0; i <= n; i++) {
        idxp[p[i]].insert(i);
    }
    for (int i = n + 1; i >= 1; i--) {
        idxs[s[i]].insert(-i);
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int x = (p[r] ^ p[l - 1]);
        bool db = x == 0;

        int xp = x ^ p[l - 1];
        auto first = idxp[xp].lower_bound(l);
        int L = N, R = -1;
        if (first != end(idxp[xp]) && *first <= r) {
            L = *first;
        }

        int xs = x ^ s[r + 1];
        auto first2 = idxs[xs].lower_bound(-r);
        if (first2 != end(idxs[xs]) && *first2 < -l) {
            R = -*first2;
        }
        db |= L < R;

        cout << (db ? "YES" : "NO") << endl;
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
