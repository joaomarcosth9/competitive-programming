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

ll mult(ll x, ll l, ll r) {
    if (l == 0) return (r / x) + 1;
    else return (r / x) - ((l - 1) / x);
}

void solve() {
    ll a, m, l, r;
    long long A, M, L, R;
    cin >> A >> M >> L >> R;
    a = A, m = M, l = L, r = R;
    
    l -= a, r -= a;
    a = 0;

    if ((l >= 0) == (r >= 0)) {
        if (l < 0) {
            l = -l, r = -r;
        }
        if (l > r) swap(l, r);
        cout << (long long)mult(m, l, r) << endl;
    } else {
        l = -l;
        if (l > r) swap(l, r);
        cout << (unsigned long long)mult(m, 0, r) + (unsigned long long)mult(m, 0, l) - 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
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
