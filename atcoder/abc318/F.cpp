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
    vector<ll> pts(n), a(n);
    for (int i = 0; i < n; i++) cin >> pts[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(pts));
    sort(all(a));
    debug(pts);
    debug(a);
    vector l(n, vector<ll> (n));
    vector r(n, vector<ll> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            l[i][j] = pts[j] - a[i];
            r[i][j] = pts[j] + a[i];
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        debug(l[i]);
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        debug(r[i]);
    }
    for (int x = -20; x <= 20; x++) {
        bool db = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                db &= l[i][j] <= x && r[i][j] >= i;
            }
        }
        if (db) cout << x << " ";
    }
    cout << endl;
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
