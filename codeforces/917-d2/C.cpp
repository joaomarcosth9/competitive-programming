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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

void solve() {
    int n, k, d; cin >> n >> k >> d;
    vector<ll> a(n), v(k);
    for (ll &x : a) cin >> x;
    for (ll &x : v) cin >> x;

    for (int i = 0; i < k; i++) v.eb(v[i]);
    for (int i = 0; i < k; i++) v.eb(v[i]);
    for (int i = 0; i < k; i++) v.eb(v[i]);
    for (int i = 0; i < k; i++) v.eb(v[i]);
    for (int i = 0; i < k; i++) v.eb(v[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == (i + 1)) {
            cnt++;
        }
    }

    ll res = 0;

    for (int i = 0; i < min((int)size(v), d); i++) {
        res = max(res, (ll)cnt + ((ll)d - 1 - i) / 2);

        cnt = 0;

        for (int j = 0; j < n; j++) {
            if (j < v[i]) a[j]++;
            if (a[j] == (j + 1)) cnt++;
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
