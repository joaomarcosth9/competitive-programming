#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define lsb(u) (u & (-u))
const int mod = 1e8, maxu = 2e3 + 5;
typedef long long ll;

struct fenwick2d {
    int n;
    ll bit[maxu][maxu];
    ll query(int i, int j) {
        ll ans = 0;
        for (int x = i; x; x -= lsb(x)) {
            for (int y = j; y; y -= lsb(y)) {
                ans += bit[x][y];
            }
        }
        return ans;
    }
    void update(int i, int j, ll u) {
        for (int x = i; x < maxu; x += lsb(x)) {
            for (int y = j; y < maxu; y += lsb(y)) {
                bit[x][y] += u;
            }
        }
    }
} ft1, ft2, ft3;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] += 1001;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] += 1001;
    }
    vector<ll> next(n), prev(n);
    for (int i = n - 1; i >= 0; i--) {
        ll curr = ft1.query(maxu - a[i] - 1, maxu - b[i] - 1);
        next[i] = curr;
        ft1.update(maxu - a[i], maxu - b[i], 1);
    }
    bool flag = 0;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll curr = ft3.query(a[i] - 1, b[i] - 1);
        prev[i] = curr;
        res = (res + prev[i] * next[i]);
        if (res > mod) {
            flag = 1;
            res %= mod;
        }
        ft3.update(a[i], b[i], ft2.query(a[i] - 1, b[i] - 1));
        ft2.update(a[i], b[i], 1);
    }
    auto ress = to_string(res);
    if (flag) {
        while (ress.size() < 8) {
            ress.insert(begin(ress), '0');
        }
    }
    cout << ress << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
