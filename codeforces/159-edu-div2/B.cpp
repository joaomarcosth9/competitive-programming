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
#define int long long 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

ll solve() {
    int n, P, l, t; cin >> n >> P >> l >> t;
    ll res = -1;

    ll td = 1 + (n - 1) / 7;
    bool add = td % 2;

    td /= 2;

    ll rd = n - td;
    debug(n, td);

    ll L = 0, R = n;

    while (L <= R) {
        ll mid = midpoint(L, R);
        ll curr = mid;
        ll now = 0;
        if (mid <= td) {
            now = curr * (2 * t + l);
        } else {
            now = td * (2 * t + l);
            curr -= td;
            if (add) {
                now += t + l;
                curr--;
            }
            if (mid) {
                now += curr * l;
            }
        }
        if (now >= P) {
            res = mid;
            R = mid - 1;
        } else L = mid + 1;
    }

    debug(res);

    return n - res;
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
