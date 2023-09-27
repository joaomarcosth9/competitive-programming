#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    map<char, int> freq;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        freq[s[i]]++;
        mx = max(mx, freq[s[i]]);
        if (s[i] == s[n - 1 - i]) {
            mp[s[i]]++;
        }
    }
    multiset<int> st;
    for (auto [_, f] : mp) {
        st.insert(f / 2);
    }
    /* auto a = st; */
    /* while(!a.empty()){ */
    /*     cout << *a.begin() << ' '; */
    /*     a.erase(a.begin()); */
    /* } */
    /* cout << '\n'; */
    if ((n & 1) || (mx > (n + 1) / 2)) {
        cout << -1 << '\n';
        return;
    }
    int res = 0;
    while (st.size() > 1) {
        auto M = *st.begin();
        auto m = *st.rbegin();
        st.erase(st.begin());
        st.erase(--st.end());
        res++;
        if (M > 1) st.insert(M - 1);
        if (m > 1) st.insert(m - 1);
    }
    if (st.size() == 1) {
        res += *st.begin();
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
