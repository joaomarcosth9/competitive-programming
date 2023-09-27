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
    vector<int> res(n);
    res[0] = 0, mp[s[0]] = 1;
    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (mp[c] == 1) {
            res[i] = 0;
        } else if (mp[c] == 2) {
            res[i] = 1;
        } else {
            mp[c] = (mp[s[i - 1]] == 1 ? 2 : 1);
            res[i] = (mp[c] == 1 ? 0 : 1);
        }
    }
    for (int i = 1; i < n; i++) {
        if (res[i] == res[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
