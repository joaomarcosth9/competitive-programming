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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k >= 3) {
        cout << 0 << endl;
        return;
    }

    if (k == 1) {
        ll res = a[0];
        for (int i = 0; i < n; i++) {
            res = min(res, a[i]);
            for (int j = i + 1; j < n; j++) {
                res = min(res, abs(a[i] - a[j]));
            }
        }
        cout << res << endl;
    } else {
        ll res = a[0];
        vector<ll> vals;
        for (int i = 0; i < n; i++) {
            res = min(res, a[i]);
            for (int j = i + 1; j < n; j++) {
                vals.eb(abs(a[i] - a[j]));
                res = min(res, abs(a[i] - a[j]));
            }
        }
        sort(all(vals));
        sort(all(a));

        for (int i = 0; i < (int)vals.size(); i++) {
            int it = lower_bound(all(a), vals[i]) - begin(a);
            if (it >= 0 && it < n) {
                res = min(res, abs(vals[i] - a[it]));
            }
            if (it - 1 >= 0 && it - 1 < n) {
                res = min(res, abs(vals[i] - a[it - 1]));
            }
        }

        cout << res << endl;
    }

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
