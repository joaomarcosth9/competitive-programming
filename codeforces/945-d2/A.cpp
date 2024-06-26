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
    int a, b, c; cin >> a >> b >> c;

    if ((a + b + c) % 2 == 1) {
        cout << -1 << endl;
        return;
    }

    int res = 0;

    multiset<int> st;
    if (a > 0) st.emplace(a);
    if (b > 0) st.emplace(b);
    if (c > 0) st.emplace(c);
    while (st.size() >= 2) {
        auto u = *st.rbegin();
        st.erase(--st.end());
        auto v = *st.rbegin();
        st.erase(--st.end());
        res++;
        if (u > 1) st.emplace(u - 1);
        if (v > 1) st.emplace(v - 1);
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