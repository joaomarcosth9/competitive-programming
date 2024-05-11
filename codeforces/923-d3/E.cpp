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
    int n, k; cin >> n >> k;
    multiset<ll> teste;

    vector<int> res(n);
    int mx = n, mn = 1;

    for (int i = 0; i < k; i++) {
        if (i & 1) {
            for (int j = i; j < n; j += k) res[j] = mx--;
        } else {
            for (int j = i; j < n; j += k) res[j] = mn++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
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
