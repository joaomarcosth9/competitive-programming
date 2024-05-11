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
    int q; cin >> q;
    vector<int> a;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            a.push_back(x);
        } else {
            int k; cin >> k;
            cout << a[a.size() - k] << endl;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
