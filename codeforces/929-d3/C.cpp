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
    int a, b, l; cin >> a >> b >> l;
    ll aa = 1;
    ll res = 0;
    set<int> st;
    for (int i = 0; i <= 25 && aa <= l; i++) {
        ll bb = 1;
        for (int j = 0; j <= 25 && bb <= l; j++) {
            if (l % (aa * bb) == 0) {
                ll k = l / (aa * bb);
                if (st.count(k)) continue;
                st.insert(k);
                res += 1;
            }
            bb *= b;
        }
        aa *= a;
    }
    cout << res << endl;
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
