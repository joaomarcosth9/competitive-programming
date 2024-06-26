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
    int n, m; cin >> n >> m;
    string s; cin >> s;

    vector<int> upd(m);
    for (int &i : upd)
        cin >> i, i--;

    string t; cin >> t;

    sort(upd.begin(), upd.end());
    sort(t.begin(), t.end());

    debug(s);
    debug(upd);
    debug(t);

    int ptr = 0, ptrchar = 0;

    while (ptr < m) {
        int r = ptr;
        while (r < m && upd[r] == upd[ptr]) r++;
        r--;
        int j = upd[ptr];
        s[j] = t[ptrchar++];
        ptr = r + 1;
    }

    cout << s << endl;

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