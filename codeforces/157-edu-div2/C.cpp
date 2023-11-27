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

    vector<string> a, b;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        a.eb(s);
        /* if ((int)size(s) & 1) a.eb(s); */
        /* else b.eb(s); */
    }

    sort(all(a), L2(size(x) < size(y)));

    /* for (auto &u : b) for (auto &x : u) x -= '0'; */

    vector<vector<ll>> vis(15, vector<ll> (101));

    ll res = 0;
    debug(a);

    for (int i = 0; i < n; i++) {
        int m = size(a[i]);

        int all_sum = accumulate(all(a[i]), -48 * m);

        debug(m, all_sum, vis[m][all_sum]);

        int sum = 0;

        for (int j = 0; j < m; j++) {
            sum += a[i][m - 1 - j] - 48;
            int len = (j + 1) * 2;
            if (len > m) {
                debug(i, a[i], m, len, sum);
                int needlen = len - m;
                if (needlen >= m) continue;
                int osum = all_sum - sum;
                int need = sum - osum;
                debug(needlen, osum, need);
                if (needlen >= 0 && need >= 0) res += vis[needlen][need];
            }
        }

        sum = 0;
        for (int j = 0; j < m; j++) {
            sum += a[i][j] - 48;
            int len = (j + 1) * 2;
            if (len > m) {
                debug(i, a[i], m, len, sum);
                int needlen = len - m;
                if (needlen >= m) continue;
                int osum = all_sum - sum;
                int need = sum - osum;
                debug(needlen, osum, need);
                if (needlen >= 0 && need >= 0) res += vis[needlen][need];
            }
        }

        vis[m][all_sum] += 1;
        res++;

    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 100; j++) {
            ll now = vis[i][j];
            res += now * (now - 1);
        }
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
