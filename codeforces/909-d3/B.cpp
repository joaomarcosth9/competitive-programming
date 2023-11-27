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

ll solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    vector<ll> d;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        if (i * i == n) d.eb(i);
        else d.eb(i), d.eb(n / i);
    }
    ll res = 0;
    for (int u : d) {
        ll mn = LLONG_MAX, mx = LLONG_MIN;
        for (int i = u; i <= n; i += u) {
            ll now = pref[i] - pref[i - u];
            mn = min(mn, now);
            mx = max(mx, now);
        }
        res = max(res, mx - mn);
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
