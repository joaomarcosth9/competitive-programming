#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = unsigned long long;
using LL = __int128_t;

void solve() {
    ll pot = 1;
    vector<LL> p;
    LL now = 0;
    for (int i = 0; i <= 12; i++) {
        now += pot;
        p.emplace_back(now);
        pot *= 10;
    }
    debug(p);
    int n = size(p);
    vector<LL> all;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                all.emplace_back((LL)p[i] + p[j] + p[k]);
            }
        }
    }
    sort(begin(all), end(all));
    all.erase(unique(begin(all), end(all)), end(all));
    int k; cin >> k;
    cout << (long long)all[k - 1] << endl;
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
