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
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> f(61);
    vector<ll> p2(61);
    p2[0] = 1;
    for (int i = 1; i <= 60; i++) p2[i] = p2[i - 1] * 2 % mod;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 60; j++) if (a[i] & (1ll << j)) f[j]++;
    }

    ll res = 0;

    for (int i = 0; i < n; i++) {
        ll AND = 0;
        for (int j = 0; j <= 60; j++) {
            if (a[i] & (1ll << j)) {
                AND += p2[j] * f[j] % mod;
                AND %= mod;
            }
        }
        for (int j = 0; j <= 60; j++) {
            if (a[i] & (1ll << j)) {
                res += (AND * p2[j] % mod) * n % mod;
                res %= mod;
            } else {
                res += (AND * p2[j] % mod) * f[j] % mod;
                res %= mod;
            }
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
