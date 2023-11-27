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
    ll res = LLONG_MAX;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> b(n), f(n);
    for (int i = 0; i < n; i++) f[i] = a[i] + i;
    for (int i = n - 1; i >= 0; i--) b[i] = a[i] + n - 1 - i;

    vector<ll> pref(n), suff(n);

    pref[0] = b[0];
    for (int i = 1; i < n; i++) pref[i] = max(pref[i - 1], b[i]);

    suff[n - 1] = f[n - 1];
    for (int i = n - 2; i >= 0; i--) suff[i] = max(suff[i + 1], f[i]);

    for (int i = 0; i < n; i++) {
        ll now = a[i];
        if (i < n - 1) now = max(now, suff[i + 1]);
        if (i > 0) now = max(now, pref[i - 1]);
        res = min(res, now);
    }

    cout << res << endl;
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
