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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> where(n, {-1, -1});
    vector<int> f(n);
    set<int> st;
    vector<vector<int>> a(m);
    int tot = 2 * n;

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            a[i][j]--;
            if (where[a[i][j]].first == -1) where[a[i][j]].first = i;
            else where[a[i][j]].second = i;
        }
        f[a[i].back()]++;
    }

    for (int i = 0; i < n; i++) {
        if (f[i] == 2) st.insert(i);
    }

    while (st.size()) {
        auto k = *st.begin();
        st.erase(st.begin());

        f[k] = 0;
        tot -= 2;

        auto [u, v] = where[k];
        a[u].pop_back();
        a[v].pop_back();

        if (a[u].size()) {
            f[a[u].back()]++;
        }
        if (a[v].size()) {
            f[a[v].back()]++;
        }

        if (a[u].size()) {
            if (f[a[u].back()] == 2) st.insert(a[u].back());
        }
        if (a[v].size()) {
            if (f[a[v].back()] == 2) st.insert(a[v].back());
        }
    }
    
    return tot == 0;
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
