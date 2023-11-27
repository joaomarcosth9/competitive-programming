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
    ll n, m; cin >> n >> m;

    if ((n % m) == 0) return 0;

    ll g = gcd(n, m);

    ll M = m / g;
    if (M != (M & (-M))) return -1;

    n %= m;

    debug(n, m);

    int it = __builtin_clz(1) - __builtin_clz(m);
    
    debug(it);

    ll res = 0;
    ll N = n;
    for (int i = it - 1; i >= 0; i--) {
        res += n;
        n <<= 1;
        if (n >= m) n -= m;
    }

    assert(n == 0);
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
