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
    map<int, int> f;
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            f[x]++;
        } else if (t == 2) {
            int x;
            cin >> x;
            f[x]--;
            if (f[x] == 0) {
                f.erase(x);
            }
        } else {
            cout << f.size() << endl;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}