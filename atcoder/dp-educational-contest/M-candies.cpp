#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int maxn = 1e2 + 5, mod = 1e9 + 7;
long long a[maxn];

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> res(a[0] + 1, 1);
    for (int i = 1; i < n; i++) {
        vector<long long> pref(a[i] + res.size(), 0);
        int gap = a[i] + 1;
        for (int j = 0; j < min((int)res.size(), 100005); j++) {
            pref[j] = (pref[j] + res[j]);
            if(j + gap < (int)pref.size()) pref[j + gap] = (pref[j + gap] - res[j]);
        }
        vector<long long> newpoly;
        long long ac = 0;
        for (int j = 0; j < min((int)pref.size(), 100005); j++) {
            ac = (ac + pref[j] + mod) % mod;
            newpoly.emplace_back(ac);
        }
        swap(res, newpoly);
    }
    debug(res);
    cout << res[k] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
