#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

int solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    int dba = 0, dbb = 0, op = 0;

    int L = 0, R = n - 1;
    while (L < n && s[L] == t[L]) {
        if (s[L] == 'A') dba = 1;
        L++;
    }
    while (R >= 0 && s[R] == t[R]) {
        if (s[R] == 'B') dbb = 1;
        R--;
    }

    if (!dba && L < n && s[L] == 'A') return -1;
    if (!dbb && R >= 0 && s[R] == 'B') return -1;

    dba = 1, dbb = 1;
    int ac = 0;
    debug(L, R);
    for (int i = L; i <= R; i++) {
        if (s[i] == t[i]) continue;
        if (s[i] == 'A') { // t[i] == 'B'
            if (ac) {
                ac--;
                op++;
            } else {
                op++;
            }
        } else { // s[i] == 'B', t[i] == 'A'
            ac++;
        }
    }
    op += ac;

    return op;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
