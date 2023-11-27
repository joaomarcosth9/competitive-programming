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
    int n, m, p; cin >> n >> m >> p;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    sort(all(a));
    sort(all(b));
    ll res = 0;
    vector<ll> pref(m + 1);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + b[i - 1];
    }
    for (int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        int lim = p - a[i];
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (b[mid] <= lim) {
                ans = mid + 1;
                l = mid + 1;
            } else r = mid - 1;
        }
        res += (ll)ans * a[i] + pref[ans];
        res += (ll)p * (m - ans);
    }
    cout << res << endl;
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
