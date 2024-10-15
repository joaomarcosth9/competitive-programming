#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MOD = (int)1e9 + 7;

void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    map<int, ll> contrib;
    //map<int, vector<int>> mapa;

    int bal = 0;
    contrib[0] = 1;
    //mapa[0].push_back(1);

    ll res = 0;

    for (int i = 1; i <= n; i++) {
        bal += (s[i - 1] == '1' ? 1 : -1);
        // for (auto l : mapa[bal]) {
            // res += (n - i + 1) * (l);
            // res %= MOD;
        // }
        res += (ll)(n - i + 1) * contrib[bal];
        res %= MOD;
        //mapa[bal].push_back(i + 1);
        contrib[bal] += i + 1;
    }

    cout << res << endl;
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