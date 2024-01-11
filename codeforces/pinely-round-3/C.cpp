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
#define int long long 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

ll solve() {
    int n; cin >> n;
    vector<int> l(n), r(n), c(n);

    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    sort(all(l));

    multiset<int> R(all(r));

    for (int i = n - 1; i >= 0; i--) {
        auto it = R.upper_bound(l[i]);
        debug(R, l[i]);
        debug(*it);
        r[i] = *it;
        R.erase(it);
    }

    vector<int> p(n);
    iota(all(p), 0);

    sort(all(p), L2(r[x] - l[x] > r[y] - l[y]));
    sort(all(c));

    ll res = 0;

    for (int i = 0; i < n; i++) res += c[i] * (r[p[i]] - l[p[i]]);

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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
