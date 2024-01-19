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
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    ll res = 0;
    int itl = 0, itr = n - 1;
    int itl2 = 0, itr2 = m - 1;
    while (itl <= itr) {
        ll p1 = abs(a[itr] - b[itl2]);
        ll p2 = abs(a[itl] - b[itr2]);
        if (p1 > p2) {
            res += p1;
            itr--;
            itl2++;
        } else {
            res += p2;
            itl++;
            itr2--;
        }
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
