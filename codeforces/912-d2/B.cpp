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
    vector a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        ll r = (1ll << 30) - 1;
        for (int j = 0; j < n; j++) if (j != i) {
            r &= a[i][j];
        }
        res[i] = r;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (i != j) {
            if (a[i][j] != (res[i] | res[j])) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto u : res) cout << u << " ";
    cout << endl;
    debug(res);
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
