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
    int q; cin >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> df(n, -1);
    for (int i = 1; i < n; i++) {
        df[i] = a[i] == a[i - 1] ? df[i - 1] : i - 1;
    }
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        l--; r--;
        if (a[r] != x) {
            cout << r + 1 << endl;
        } else {
            cout << (df[r] < l ? -1 : df[r] + 1) << endl;
        }
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
