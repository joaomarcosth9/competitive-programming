#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    int n; cin >> n;

    vector<pair<string, string>> a(n);

    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;
        a[i] = {s, t};
    }

    for (int i = 0; i < n; i++) {
        set<string> st;
        auto [s, t] = a[i];
        for (int j = 0; j < n; j++) if (j != i) {
            st.emplace(a[j].first);
            st.emplace(a[j].second);
        }
        if (st.count(s) && st.count(t)) return 0;
    }

    return 1;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
