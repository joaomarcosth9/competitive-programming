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
    string s; cin >> s;
    auto t = s;
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    map<char, char> conv;
    for (int i = 0; i < (int)t.size(); i++) {
        conv[t[i]] = t[(int)t.size() - 1 - i];
    }
    for (char c : s) cout << conv[c];
    cout << endl;
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
