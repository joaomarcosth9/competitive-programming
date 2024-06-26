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
    string s; cin >> s;
    int n = int(s.size());
    debug(s);
    int balance = 0;
    vector<int> pref(n + 1), bal(n + 1);
    for (int i = 0; i < n; i++) {
        balance += (s[i] == '(' ? 1 : -1);
        pref[i + 1] = pref[i] + balance;
        bal[i + 1] = balance;
    }

    ll res = 0;
    int l = 2;
    balance = 1;
    int neg_balance = 0;
    map<int, int> freq;
    freq[1]++;

    for (int i = 2; i < n; i++) {
        assert(l <= i);

        balance += (s[i - 1] == '(' ? 1 : -1);
        neg_balance += (s[i - 1] == '(' ? 1 : -1);
        debug(i, balance, neg_balance);
        debug(i, l);
        debug(bal);

        while (l <= i && neg_balance > bal[l - 1]) {
            freq[bal[l]]--;
            neg_balance -= (s[l - 1] == '(' ? 1 : -1); l++;
        }

        res += freq[bal[i]];
        freq[bal[i]]++;
        assert(balance == bal[i]);
        debug(l, i, res);
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