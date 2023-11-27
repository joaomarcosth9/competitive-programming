#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n; cin >> n;
    vector<ll> a(n), pref(n + 1);
    for (ll &i : a) cin >> i;
    for (int j = 1; j < n; j++) {
        if (j & 1) pref[j] = pref[j - 1];
        else pref[j] = pref[j - 1] + (a[j] - a[j - 1]);
    }
    debug(pref);

    int q; cin >> q;

    while (q--) {
        ll l, r; cin >> l >> r;
        auto it = lower_bound(all(a), l);
        auto it2 = lower_bound(all(a), r);
        int i = it - begin(a);
        int j = it2 - begin(a);
        debug(l, i);
        debug(r, j);
        ll res = 0;
        res = pref[j] - pref[i];
        debug(res);
        if ((i % 2) == 0) {
            res += (a[i] - l);
        }
        if ((j % 2) == 0) {
            res -= (a[j] - r);
        }
        cout << res << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
