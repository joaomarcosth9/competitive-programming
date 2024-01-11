#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

ll solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> l, r;

    l.emplace_back(a[0]);

    int it = 1;
    while (it < n && a[it] <= l.back()) l.emplace_back(a[it]), it++;
    if (it < n) r.emplace_back(a[it]), it++;

    for (int i = it; i < n; i++) {
        int u = 0;
        u |= (a[i] > l.back()) << 0;
        u |= (a[i] > r.back()) << 1;
        if (u == 0) {
            if (l.back() >= r.back()) {
                r.emplace_back(a[i]);
            } else {
                l.emplace_back(a[i]);
            }
        } else if (u == 1) {
            r.emplace_back(a[i]);
        } else if (u == 2) {
            l.emplace_back(a[i]);
        } else if (u == 3) {
            if (l.back() >= r.back()) {
                r.emplace_back(a[i]);
            } else {
                l.emplace_back(a[i]);
            }
        }
    }

    ll res = 0;

    for (int i = 1; i < (int)size(l); i++) {
        res += l[i] > l[i - 1];
    }
    for (int i = 1; i < (int)size(r); i++) {
        res += r[i] > r[i - 1];
    }

    return res;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
