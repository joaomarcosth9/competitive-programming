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
    vector<int> a(n), p;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cmex = 0;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            p.push_back(cmex - a[i]);
        } else {
            p.push_back(cmex);
        }
        vis[p.back()]++;
        while (cmex < n && vis[cmex]) cmex++;
    }
    for (auto u : p) cout << u << " ";
    cout << endl;
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
