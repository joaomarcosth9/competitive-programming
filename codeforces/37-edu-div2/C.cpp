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
    string s; cin >> s;
    
    set<int> st;
    int curr = 0;
    int L = 0;
    bool db = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            st.insert(a[i]);

            int it = L;
            for (auto u : st) {
                if (++it != u) db = 0;
            }

            st.clear();
            L = i + 1;
        } else {
            st.insert(a[i]);
        }
    }

    cout << (db ? "YES" : "NO") << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
