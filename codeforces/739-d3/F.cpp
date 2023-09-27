#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve() {
    string s;
    int k, n;
    cin >> s >> k;
    n = s.size();
    while (1) {
        db("FORA", s);
        set<char> st;
        for (int j = 0; j < n; j++) {
            st.insert(s[j]);
        }
        if ((int)st.size() <= k) {
            cout << s << endl;
            return;
        }
        st.clear();
        int i = 0;
        while (1) {
            st.insert(s[i]);
            if ((int)st.size() > k) {
                while (s[i] == '9') {
                    i--;
                }
                s[i]++;
                for (int j = i + 1; j < n; j++) {
                    s[j] = '0';
                }
                break;
            }
            db(s);
            i++;
        }
    }
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
