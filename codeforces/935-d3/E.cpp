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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    a.insert(begin(a), 0);

    vector<pair<int, int>> res;

    set<int> vis;
    int pos_x = -1;

    int l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] <= x) {
            vis.insert(a[m]);
            if (a[m] == x) pos_x = m;
            l = m;
        } else r = m;
    }
    vis.insert(a[l]);

    if (a[l] == x) {
        cout << 0 << endl;
    } else {
        if (pos_x == -1) {
            pos_x = (int)(find(a.begin(), a.end(), x) - a.begin());
            cout << 1 << endl;
            cout << l << " " << pos_x << endl;
            swap(a[l], a[pos_x]);
        } else if (a[l] < x) {
            cout << 1 << endl;
            cout << l << " " << pos_x << endl;
            swap(a[l], a[pos_x]);
        } else {
            // a[l] > x
            cout << 2 << endl;
            cout << l << " " << pos_x << endl;
            swap(a[l], a[pos_x]);
            for (int i = 1; i <= n; i++) {
                if (vis.count(a[i])) continue;
                if (a[i] < x) {
                    cout << i << " " << pos_x << endl;
                    swap(a[i], a[pos_x]);
                    break;
                }
            }
        }
    }
    
    l = 1, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (a[m] <= x) {
            l = m;
        } else r = m;
    }
    assert(a[l] == x);
}

int32_t main() {
    /* cin.tie(0)->sync_with_stdio(0); */
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
