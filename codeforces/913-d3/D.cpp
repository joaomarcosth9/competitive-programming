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
    vector<ll> l(n), r(n);

    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    ll L = 0, R = 1e9;
    ll ans = -1;

    while (L <= R) {
        ll mid = midpoint(L, R);
        ll mn = 0, mx = 0;
        bool db = 1;
        for (int i = 0; i < n; i++) {
            mn = mn - mid;
            mx = mx + mid;
            if (mn > r[i] || mx < l[i]) {
                db = 0;
                break;
            }
            mn = max(mn, l[i]);
            mx = min(mx, r[i]);
        }
        if (db) {
            ans = mid;
            R = mid - 1;
        } else L = mid + 1;
    }

    cout << ans << endl;
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
