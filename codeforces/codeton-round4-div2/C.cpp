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
    int n;
    ll c, d; cin >> n >> c >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int N = n;

    sort(all(a));
    ll res1 = 0, res2 = 0;

    a.erase(unique(all(a)), end(a));
    res1 += (n - (int)size(a)) * c;

    n = size(a);

    debug(res1);
    debug(n, c, d);
    debug(a);

    ll res = LLONG_MAX;

    for (int i = n - 1; i >= 0; i--) {
        int sz = i + 1;
        ll cres = (a[i] - sz) * d;
        res = min(res, cres + res1);
        res1 += c;
    }

    cout << min(res, N * c + d) << endl;
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
