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
    for (int &i : a)
        cin >> i;

    int vis[2] = {0, 0};

    for (int i = 0; i < n; i++) {
        int p  = a[i] & 1;
        if (vis[p ^ 1]) {
            cout << -1 << endl;
            return;
        }
        vis[p]++;
    }

    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    vector<int> ops;

    while (mx != mn) {
        int x = (mx + mn) / 2;
        ops.push_back(x);
        for (int i = 0; i < n; i++) {
            a[i] = abs(a[i] - x);
        }
        mx = *max_element(a.begin(), a.end());
        mn = *min_element(a.begin(), a.end());
    }

    if (mx != 0) {
        ops.push_back(mx);
    }

    cout << ops.size() << endl;

    for (auto u : ops) {
        cout << u << " ";
    }
    cout << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}