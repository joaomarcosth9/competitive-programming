#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n, L, R; cin >> n >> L >> R;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int res = 0;
    vector<vector<int>> b;
    for (int i = 0; i < n; i++) {
        if (a[i] >= L && a[i] <= R) {
            res++;
        } else if (a[i] < L) {
            int j = i;
            b.emplace_back();
            while (j < n && a[j] < L) {
                b.back().push_back(a[j++]);
            }
            i = j - 1;
        }
    }
    for (auto v : b) {
        debug(res, v);
        int m = (int)v.size();
        vector<ll> p(m + 1);
        for (int i = 0; i < m; i++) {
            p[i + 1] = p[i] + v[i];
        }
        int i = 0;
        while (i < m) {
            int l = i, r = m - 1, ans = i;
            while (l <= r) {
                int mid = midpoint(l, r);
                if (p[mid + 1] - p[i] >= L) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (p[ans + 1] - p[i] >= L && p[ans + 1] - p[i] <= R) {
                res++;
                i = ans + 1;
            } else {
                i++;
            }
        }
    }
    cout << res << endl;
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