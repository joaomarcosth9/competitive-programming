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
typedef __int128_t ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

ll sq(ll x) {
    ll l = 1, r = x;
    ll ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

ll solve() {
    ll sum = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
    }
    return sq(sum) * sq(sum) == sum;
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
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
        TEST += 1;
    }
}

