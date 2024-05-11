#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAX = 2e5 + 5, MAX2 = 18;

namespace stmin {
    int m[MAX2][MAX], n;
    void build(vector<int> v) {
        n = (int)v.size();
        for (int i = 0; i < n; i++) m[0][i] = v[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i + (1 << j) <= n; i++) m[j][i] = min(m[j - 1][i], m[j - 1][i + (1 << (j - 1))]);
    }
    int query(int a, int b) {
        int j = __builtin_clz(1) - __builtin_clz(b - a + 1);
        return min(m[j][a], m[j][b - (1 << j) + 1]);
    }
}

namespace stmax {
    int m[MAX2][MAX], n;
    void build(vector<int> v) {
        n = (int)v.size();
        for (int i = 0; i < n; i++) m[0][i] = v[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i + (1 << j) <= n; i++) m[j][i] = max(m[j - 1][i], m[j - 1][i + (1 << (j - 1))]);
    }
    int query(int a, int b) {
        int j = __builtin_clz(1) - __builtin_clz(b - a + 1);
        return max(m[j][a], m[j][b - (1 << j) + 1]);
    }
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n);
    vector<int> bad(n);
    vector<pair<int, int>> look;
    
    int last = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < y || a[i] > x) {
            bad[i] = 1;
            look.push_back({last + 1, i - 1});
            last = i;
        }
    }

    if (!bad[n - 1]) look.push_back({last + 1, n - 1});

    stmax::build(a);
    stmin::build(a);

    ll res = 0;

    for (auto [l, r] : look) if (l <= r) {
        for (int i = l; i <= r; i++) {
            int L = l - 1, R = i + 1;
            while (R - L > 1) {
                int M = (L + R) >> 1;
                int MX = stmax::query(M, i);
                int MN = stmin::query(M, i);
                if (MX == x && MN == y) {
                    L = M;
                } else R = M;
            }
            debug(l, r);
            debug(L);
            if (L >= l) {
                res += L - l + 1;
            }
        }
    }

    cout << res << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
