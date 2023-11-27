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
typedef __int128_t LL;
typedef tuple<int, int, int> i3;

void solve() {
    ll x, y, l, r; cin >> x >> y >> l >> r;
    vector<ll> px, py;
    px.eb(1), py.eb(1);
    while ((LL)px.back() * x <= r) px.eb(px.back() * x);
    while ((LL)py.back() * y <= r) py.eb(py.back() * y);
    vector<ll> unlucky;
    unlucky.eb(l - 1);
    for (int i = 0; i < (int)px.size(); i++) {
        for (int j = 0; j < (int)py.size(); j++) {
            ll now = px[i] + py[j];
            if (now >= l && now <= r) unlucky.eb(now);
        }
    }
    debug(px);
    debug(py);
    unlucky.eb(r + 1);
    sort(all(unlucky));
    ll res = 0;
    debug(unlucky);
    for (int i = 1; i < (int)unlucky.size(); i++) {
        res = max(res, unlucky[i] - unlucky[i - 1] - 1);
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
