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
    string s, t; cin >> s >> t;
    int n = (int)s.size();
    int m = (int)t.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && s[i] != t[j]) {
            j++;
        }
        cout << j + 1 << " ";
        j++;
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
