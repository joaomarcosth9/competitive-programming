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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    vector<int> id(n);
    for (int i = 0; i < n; i++) {
        id[a[i] - 1] = i;
    }
    set<int> st;
    int res = INT_MAX;
    for (int i = 0; i < k; i++) {
        st.insert(id[i]);
    }
    res = min(res, *st.rbegin() - *st.begin());
    for (int i = k; i < n; i++) {
        st.erase(id[i - k]);
        st.insert(id[i]);
        res = min(res, *st.rbegin() - *st.begin());
    }
    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
