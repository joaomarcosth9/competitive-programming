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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool in = 0;
    int first = n;
    int last = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i]) first = i;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) last = i;
    }
    for (int j = last; j >= first; j--) {
        if (a[j] == 0) res++;
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
