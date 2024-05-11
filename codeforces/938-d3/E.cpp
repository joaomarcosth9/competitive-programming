#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAX = 5015;
int a[MAX], flip[MAX];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c == '1';
    }
    int res = 0;
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n + 5; i++) {
            flip[i] = 0;
        }
        bool db = 1;
        int ac = 0;
        for (int i = 0; i < n; i++) {
            ac ^= flip[i];
            if ((a[i] ^ ac) == 0) {
                if (i + len - 1 < n) {
                    flip[i + len] ^= 1;
                    flip[i] ^= 1;
                    ac ^= 1;
                } else {
                    db = 0;
                }
            }
        }
        if (db) res = len;
    }
    cout << res << endl;
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
