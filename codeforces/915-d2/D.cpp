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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    rotate(begin(a), min_element(all(a)) + 1, end(a));

    set<pair<int, int>> mex;
    mex.emplace(0, n - 1);
    mex.emplace(n, 1);

    debug(a);
    debug(mex);

    ll curr = n;
    ll best = curr;

    for (int i = 0; i < n - 1; i++) {
        ll add = 0;

        while (mex.size()) {
            auto [val, freq] = *rbegin(mex);
            if (val < a[i]) break;
            add += freq;
            curr -= (ll)val * freq;
            mex.erase(--end(mex));
        }
        if (add) mex.emplace(a[i], add);
        curr += a[i] * add;

        curr += n;
        mex.emplace(n, 1);
        best = max(best, curr);
    }

    cout << best << endl;
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
