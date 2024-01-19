#include "bits/stdc++.h"
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
    for (int &i : a) cin >> i;
    sort(begin(a), end(a));
    ll res = 0;
    map<int, ll> X;
    map<int, ll> first;
    debug(a);
    for (int i = 0; i < n; i++) {
        if (!first.count(a[i])) first[a[i]] = i;
        res += (ll)X[a[i]] * first[a[i]];
        res += (ll)X[a[i]] * (X[a[i]] - 1) / 2;
        X[a[i]]++;
    }
    cout << res << endl;
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
