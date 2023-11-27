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
    ll n, x, k; cin >> n >> x >> k;
    auto cntdis = [&] (ll y, ll t) {
        if (t < 0) return 0ll;
        if (y > n) return 0ll;
        if (t == 0) return 1ll;
        ll l = y, r = y;
        ll dis = 0;
        while (l <= n) {
            l = (l * 2);
            r = (r * 2) + 1;
            dis++;
            if (dis == t) {
                r = min(r, n);
                return max(0ll, r - l + 1);
            }
        }
        return 0ll;
    };
    ll ret = cntdis(x, k);
    debug(ret);
    while (x > 1 && k > 0) {
        x ^= 1;
        ret += cntdis(x, k - 2);
        k--;
        x /= 2;
        if (k == 0) ret++;
    }
    return ret;
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
