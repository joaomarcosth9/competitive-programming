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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    vector<ii> b(m);
    for (int i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
    sort(all(a));
    sort(all(b));
    int ac = 0;
    for (int i = 0; i < n; i++) {
        ac += a[i];
    }
    for (int i = 0; i < m; i++) {
        auto [l, r] = b[i];
        if (ac >= l && ac <= r) {
            cout << ac << endl;
            return;
        }
        if (l >= ac) {
            cout << l << endl;
            return;
        }
    }
    cout << -1 << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
