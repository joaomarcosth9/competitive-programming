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
    ll n, d, p; cin >> n >> d >> p;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    sort(rall(a));
    ll N = (n + d);
    vector<ll> pref(2 * N + 1);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];
    for (int i = n + 1; i <= 2 * N; i++) pref[i] = pref[i - 1];
    ll res = pref[n];
    debug(a);
    for (int i = 0; i < n; i++) {
        ll now = pref[i + d] - pref[i];
        if (now > p) res -= now, res += p, i += d - 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
