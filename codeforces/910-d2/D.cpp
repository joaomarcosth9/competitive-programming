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
#define int ll

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    int minn = 1e9 + 1, maxx = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        maxx = max(maxx, a[i]);
        minn = min(minn, b[i]);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += b[i] - a[i];

    ll best = 0;
    for (int i = 0; i < n; i++) {
        if (minn < a[i]) {
            best = max(best, 2 * (a[i] - minn));
        }
        if (maxx > b[i]) {
            best = max(best, 2 * (maxx - b[i]));
        }
    }

    cout << ans + best << endl;

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
