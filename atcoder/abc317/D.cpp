#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
#define int ll

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        for (auto &j : a[i]) cin >> j;
    }
    vector<int> v, w;
    int V = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][1] > a[i][0]) {
            V += a[i][2];
            v.eb(2 * a[i][2]);
            w.eb((a[i][1] - a[i][0] + 1) / 2);
        } else
            V -= a[i][2];
    }
    if (V <= 0) {
        cout << 0 << endl;
        return;
    }
    const int INF = 1e18;
    int N = size(w);
    debug(V);
    debug(N);
    debug(v);
    debug(w);
    vector dp(N + 1, vector<int>(V + 100001, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (j = 0; j <= V + 100000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (v[i - 1] <= j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            }
        }
    }

    ll res = LLONG_MAX;
    for (int i = V; i <= V + 100000; i++) {
        res = min(res, (ll)dp[N][i]);
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
}
