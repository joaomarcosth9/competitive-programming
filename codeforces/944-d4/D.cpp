#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

int solve() {
    string s; cin >> s;
    int n = (int)s.size();

    bool ok = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] < s[i]) ok = 0;
    }
    if (ok) return 1;

    int l = -1, r = n;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '1') {
            l = i, r = i + 1;
            while (l > 0 && s[l - 1] == '0') l--;
            while (r < n - 1 && s[r + 1] == '1') r++;
            break;
        }
    }

    if (l == -1 && r == n) {
        return 2;
    }

    int res = 1;
    if (l > 0) {
        char cur = s[0];
        res++;
        for (int i = 1; i < l; i++) {
            if (s[i] != cur) {
                cur = s[i];
                res++;
            }
        }
    }
    if (r < n - 1) {
        char cur = s[n - 1];
        res++;
        for (int i = n - 1; i > r; i--) {
            if (s[i] != cur) {
                cur = s[i];
                res++;
            }
        }
    }

    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
