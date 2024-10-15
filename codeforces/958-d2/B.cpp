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
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) {
        char c; cin >> c;
        i = c - '0';
    }
    int g = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && last != 0) {
            g++;
            last = a[i];
        } else {
            if (a[i] != 0) {
                last = a[i];
            }
        }
    }
    if (count(a.begin(), a.end(), 1) > g) {
        return true;
    }
    return false;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    /* solve(); */
    /* cout << solve() << endl; */
    int tt; cin >> tt;
    while (tt--)
        cout << (solve() ? "Yes" : "No") << endl;
}
