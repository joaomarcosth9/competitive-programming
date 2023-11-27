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
typedef __int128_t LL;

LL ceil(LL a, LL b) {
    return a / b + bool(a % b);
}

LL time(LL a, LL b, LL h) {
    if (a >= h) return 1;
    return 1LL + ceil(h - a, a - b);
}

void solve() {
    int q; cin >> q;
    LL big = (LL)4e18;
    LL mn = 1, mx = big;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            ll a, b, n; cin >> a >> b >> n;
            LL mnn = big + 1, mxx = 0;
            LL l = 1, r = big;
            while (l <= r) {
                LL mid = l + (r - l) / 2;
                LL now = time(a, b, mid);
                if (now < n) {
                    l = mid + 1;
                } else if (now >= n) {
                    r = mid - 1;
                    if (now == n) mnn = mid;
                }
            }
            l = 1, r = big;
            while (l <= r) {
                LL mid = l + (r - l) / 2;
                LL now = time(a, b, mid);
                if (now > n) {
                    r = mid - 1;
                } else if (now <= n) {
                    l = mid + 1;
                    if (now == n) mxx = mid;
                }
            }
            if ((mx < mn) || (mxx < mn) || (mnn > mx)) {
                cout << 0 << " ";
            } else {
                cout << 1 << " ";
                mx = min(mx, mxx);
                mn = max(mn, mnn);
            }
        } else {
            ll a, b; cin >> a >> b;
            ll lb = time(a, b, mn);
            ll ub = time(a, b, mx);
            if (lb == ub) cout << lb << " ";
            else cout << -1 << " ";
        }
    }
    cout << endl;
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
