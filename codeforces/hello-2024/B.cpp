#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

ll solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        s[i] = s[i] == '+' ? 1 : -1;
    }
    ll ac = 0;
    for (int i = 0; i < n; i++) {
        ac += s[i];
    }
    return abs(ac);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
