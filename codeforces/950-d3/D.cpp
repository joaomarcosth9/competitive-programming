#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool test(vector<int> a, int idx) {
    int n = int(a.size());
    a.erase(a.begin() + idx);
    n = int(a.size());
    vector<int> b(n - 1);
    for (int i = 0; i + 1 < n; i++) {
        b[i] = gcd(a[i], a[i + 1]);
    }
    return is_sorted(b.begin(), b.end());
}

bool solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i + 1 < n; i++) {
        b[i] = gcd(a[i], a[i + 1]);
    }

    vector<int> pref_s(n), suff_s(n, INT_MAX);
    vector<int> db_pref(n), db_suff(n);

    db_pref[0] = 1;

    for (int i = 1; i < n; i++) {
        pref_s[i] = max(pref_s[i - 1], gcd(a[i - 1], a[i]));
        bool now_db = 0;
        if (gcd(a[i - 1], a[i]) >= pref_s[i - 1]) {
            now_db = 1;
        }
        db_pref[i] = now_db && db_pref[i - 1];
    }

    db_suff[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suff_s[i] = min(suff_s[i + 1], gcd(a[i], a[i + 1]));
        bool now_db = 0;
        if (gcd(a[i], a[i + 1]) <= suff_s[i + 1]) {
            now_db = 1;
        }
        db_suff[i] = now_db && db_suff[i + 1];
    }
    debug(db_pref);
    debug(db_suff);
    debug(pref_s);
    debug(suff_s);

    // testar tirar as pontas na mao

    bool db = 0;
    db |= test(a, 0);
    db |= test(a, 1);
    db |= test(a, n - 2);
    db |= test(a, n - 1);

    for (int i = 2; i < n - 2; i++) {
        // tenta
        if (db_pref[i - 1] && db_suff[i + 1]) {
            debug(i);
            int g = gcd(a[i - 1], a[i + 1]);
            db |= g >= pref_s[i - 1] && g <= suff_s[i + 1];
        }
    }

    debug(a);
    debug(b);

    return db;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        // solve();
        // cout << solve() << endl;
        cout << (solve() ? "Yes" : "No") << endl;
    }
}