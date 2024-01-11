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
    int k; cin >> k;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int mx = 0;
    ll res = 0, now = 0;

    for (int i = 0; i < min(n, k); i++) {
        now += a[i];
        int kk = k;
        mx = max(mx, b[i]);
        ll now2 = 0;

        kk -= i + 1;

        debug(i, now, mx, kk);
        debug(pref);

        if (kk > 0) {
            now2 += mx * kk;
        }

        debug(i, now, now2, now + now2, res);
        res = max(res, now + now2);
    }

    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
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
