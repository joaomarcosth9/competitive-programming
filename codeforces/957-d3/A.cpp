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
    multiset<int> st;
    for (int i = 0; i < 3; i++) {
        int x; cin >> x;
        st.insert(x);
    }
    for (int i = 0; i < 5; i++) {
        auto u = *st.begin();
        st.erase(st.begin());
        st.insert(u + 1);
    }
    ll res = 1;
    for (auto u : st) {
        res *= u;
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