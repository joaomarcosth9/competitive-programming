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

ll fat(ll i) {
    if (i == 0) return 1ll;
    return i * fat(i - 1);
}

ll ncr(ll n, ll r) {
    ll up = 1;
    ll it = r;
    while (it) {
        up *= n;
        n--;
        it--;
    }
    return up / fat(r);
}

ll solve() {
    ll n, k; cin >> n >> k;
    ll res = 1;
    for (ll i = 2; i <= k; i++) {
        ll N = n;
        ll it = i;
        ll now = ncr(n, i);
        it = 0;
        ll sign = 1;
        ll f = 0;
        while (it <= i) {
            f += sign * fat(i) / fat(it);
            it++;
            sign *= -1;
        }
        res += (now * f);
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
