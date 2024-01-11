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
    int n, q; cin >> n >> q;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) cin >> mat[i];

    vector<vector<ll>> pref(n + 1, vector<ll> (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (mat[i - 1][j - 1] == 'B');
        }
    }
    
    auto query = [&] (int a, int b) {
        ll res = 0;

        ll x = (a - 1) / n, y = (b - 1) / n;
        res += x * y * pref[n][n];

        res += y * (pref[(a - 1) % n + 1][n]);

        res += x * (pref[n][(b - 1) % n + 1]);

        res += pref[(a - 1) % n + 1][(b - 1) % n + 1];

        return res;

    };

    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a++, b++, c++, d++;
        cout << query(c, d) - query(c, b - 1) - query(a - 1, d) + query(a - 1, b - 1) << endl;
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
