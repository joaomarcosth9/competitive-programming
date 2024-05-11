#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAX = 2e5 + 5, MAX2 = 19;

namespace minst {
    pair<int, int> m[MAX2][MAX];
    int n;
    void build(int n2, pair<int, int> *v) {
        n = n2;
        for (int i = 0; i < n; i++) m[0][i] = v[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i + (1 << j) <= n; i++) m[j][i] = min(m[j - 1][i], m[j - 1][i + (1 << (j - 1))]);
    }
    pair<int, int> query(int a, int b) {
        int j = __builtin_clz(1) - __builtin_clz(b - a + 1);
        return min(m[j][a], m[j][b - (1 << j) + 1]);
    }
}

namespace maxst {
    pair<int, int> m[MAX2][MAX];
    int n;
    void build(int n2, pair<int, int> *v) {
        n = n2;
        for (int i = 0; i < n; i++) m[0][i] = v[i];
        for (int j = 1; (1 << j) <= n; j++)
            for (int i = 0; i + (1 << j) <= n; i++) m[j][i] = max(m[j - 1][i], m[j - 1][i + (1 << (j - 1))]);
    }
    pair<int, int> query(int a, int b) {
        int j = __builtin_clz(1) - __builtin_clz(b - a + 1);
        return max(m[j][a], m[j][b - (1 << j) + 1]);
    }
}

int n, q;
pair<int, int> a[MAX];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    minst::build(n, a);
    maxst::build(n, a);
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        auto [mn, idmn] = minst::query(l, r);
        auto [mx, idmx] = maxst::query(l, r);
        if (mn == mx) {
            cout << "-1 -1" << endl;
        } else {
            cout << idmn << " " << idmx << endl;
        }
    }
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
