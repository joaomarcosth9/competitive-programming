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

void solve() {
    int n; cin >> n;
    int p; cin >> p;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1]; // a_i
        a[i][2] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i][0]; // b_i
    }
    sort(all(a));

    debug(a);

    ll cost = p;
    int it = 1;

    for (int i = 0; it < n && i < n; i++) {
        if (a[i][0] <= p) {
            cost += (ll)a[i][0] * min(n - it, a[i][1]);
            it += a[i][1];
        } else {
            cost += p;
            it += 1;
        }
    }

    cout << cost << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
