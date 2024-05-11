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
    string a, b; cin >> a >> b;
    string best;
    bool done = 0;
    for (int i = 0; i < n - 1; i++) {
        best += a[i];
        if (a[i + 1] > b[i]) {
            for (int j = i; j < n; j++) {
                best += b[j];
                done = 1;
            }
            break;
        }
    }

    if (!done) {
        best += a.back();
        best += b.back();
    }

    int ways = 0;

    vector<int> gooda(n), goodb(n);

    string pref;
    for (int i = 0; i < n; i++) {
        pref += a[i];
        if (pref[i] != best[i]) {
            break;
        }
        gooda[i] = 1;
    }
    string suff;
    for (int i = n - 1; i >= 0; i--) {
        suff += b[i];
        if (suff[n - 1 - i] != best[i + 1]) {
            break;
        }
        goodb[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        ways += gooda[i] && goodb[i];
    }

    cout << best << endl << ways << endl;
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
