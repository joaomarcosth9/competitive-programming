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
    int x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x |= a[i];
    }
    auto get_or = [](vector<int> &f) {
        int ret = 0;
        for (int i = 0; i < 20; i++) {
            if (f[i] > 0) ret |= (1 << i);
        }
        return ret;
    };
    int l = 1, r = n;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        vector<int> f(20);
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < 20; j++) {
                f[j] += (a[i] >> j) & 1;
            }
        }
        bool db = get_or(f) == x;
        for (int i = mid; i < n; i++) {
            for (int j = 0; j < 20; j++) {
                f[j] += (a[i] >> j) & 1;
            }
            for (int j = 0; j < 20; j++) {
                f[j] -= (a[i - mid] >> j) & 1;
            }
            db &= get_or(f) == x;
        }
        if (db) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
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