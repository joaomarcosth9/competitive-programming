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
    vector<int> v = {6, 8, 12};
    vector<int> w = {1, 1, 1};
    for (auto &x : w) cin >> x;

    ll res = LLONG_MAX;

    for (int i = 0; i <= n; i++) {
        ll now = i * 6;
        ll cost = i * w[0];
        for (int j = 0; j <= n; j++) {
            ll now2 = now + j * 8;
            ll cost2 = cost + j * w[1];
            for (int k = 0; k <= n; k++) {
                ll now3 = now2 + k * 12;
                ll cost3 = cost2 + k * w[2];
                if (now3 >= n) {
                    res = min(res, cost3);
                }
            }
        }
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
