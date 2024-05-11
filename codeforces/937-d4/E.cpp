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
    vector<int> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    int best = n;
    for (auto len : d) {

        bool eq = 1;
        int pos_dif = -1;
        char ini, en;
        for (int j = 0; j < len; j++) {
            if (s[j] != s[n - len + j]) {
                eq = 0;
                ini = s[j];
                en = s[n - len + j];
                pos_dif = j;
            }
        }

        debug(len);
        debug(eq, pos_dif, ini, en);

        bool db = 1;
        if (eq) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (s[j] != s[j % len]) {
                    if (cnt) db = 0;
                    cnt++;
                }
            }
        } else {
            int cnt = 0;
            char should = ini;
            for (int j = len; j < 2 * len; j++) {
                if (s[j] != s[j % len]) {
                    should = en;
                    cnt++;
                }
            }
            char bkp = s[pos_dif];
            s[pos_dif] = should;
            debug(s);
            for (int j = 0; j < n; j++) {
                if (s[j] != s[j % len]) {
                    if (cnt) db = 0;
                    cnt++;
                }
            }
            s[pos_dif] = bkp;
        }

        if (db) best = min(best, len);
    }
    cout << best << endl;
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
