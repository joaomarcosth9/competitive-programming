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
    int n, m; cin >> n >> m;
    vector<pair<ll, ll>> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(all(p));

    vector<string> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    vector<string> a(n, string(m, 'Z'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) a[i][j] = A[i][p[j].second];
    }

    for (int i = 0; i < n; i++) {
        ll mx = 0, now = i + 1;
        for (int j = 0; j < m; j++) if (a[i][j] == 'o') now += p[j].first;
        for (int j = i - 1; j >= 0; j--) {
            ll now2 = j + 1;
            for (int k = 0; k < m; k++) if (a[j][k] == 'o') now2 += p[k].first;
            mx = max(mx, now2);
        }
        for (int j = i + 1; j < n; j++) {
            ll now2 = j + 1;
            for (int k = 0; k < m; k++) if (a[j][k] == 'o') now2 += p[k].first;
            mx = max(mx, now2);
        }
        ll ans = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (now > mx) break;
            else if (a[i][j] == 'x') ans++, now += p[j].first;
        }
        cout << ans << endl;
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
