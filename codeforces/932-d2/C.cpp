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
    int n, l; cin >> n >> l;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<tuple<int, int, int>> c(n);

    for (int i = 0; i < n; i++) {
        c[i] = {b[i], a[i], i};
    }
    sort(c.begin(), c.end());

    int best = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= l) {
            best = 1;
        }
    }
    debug(a);
    debug(b);
    for (int i = 0; i < n; i++) {
        auto [bb, aa, j] = c[i];
        b[i] = bb;
        a[i] = aa;
    }
    debug(a);
    debug(b);

    for (int i = 0; i < n; i++) {
        ll stsum = 0;
        multiset<int> st;
        for (int j = i; j < n; j++) {
            st.insert(a[j]);
            stsum += a[j];

            ll vb = b[j] - b[i];

            while (st.size() && stsum + vb > l) {
                stsum -= *st.rbegin();
                st.erase(--st.end());
            }

            int size = (int)st.size();
            if (stsum + vb <= l) best = max(best, size);

        }
    }

    cout << best << endl;
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
