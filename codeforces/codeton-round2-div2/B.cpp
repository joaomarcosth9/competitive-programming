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
    int n;
    ll x; cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll mn = max(0ll, a[0] - x);
    ll mx = a[0] + x;

    ll res = 0;

    for (int i = 1; i < n; i++) {
        ll mnn = max(0ll, a[i] - x);
        ll mxx = a[i] + x;
        mn = max(mnn, mn);
        mx = min(mxx, mx);
        if (mn > mx) {
            res++;
            mn = mnn;
            mx = mxx;
        }
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
