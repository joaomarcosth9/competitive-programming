#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    string s, t; cin >> s >> t;
    return (s + " " + t) == "AtCoder Land";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // solve();
    // cout << solve() << endl;
    cout << (solve() ? "Yes" : "No") << endl;
}