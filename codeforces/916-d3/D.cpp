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
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    set<ii, greater<ii>> mxa, mxb;
    for (int i = 0; i < n - 1; i++) {
        mxa.emplace(a[i], i);
        mxb.emplace(b[i], i);
    }

    ll res = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll now = 0;

        auto [xa, ida] = *begin(mxa);
        auto [xb, idb] = *begin(mxb);

        if (ida != idb) {
            now = xa + xb;
        } else {
            auto [xaa, _] = *(++begin(mxa));
            auto [xbb, __] = *(++begin(mxb));
            now = max(xaa + xb, xbb + xa);
        }

        res = max(res, c[i] + now);

        mxa.emplace(a[i], i);
        mxb.emplace(b[i], i);
        if (i > 0) {
            mxa.erase(make_pair(a[i - 1], i - 1));
            mxb.erase(make_pair(b[i - 1], i - 1));
        }
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
