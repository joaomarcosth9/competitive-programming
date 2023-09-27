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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

ld dist2(ii &a, ii &b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return sqrt((dx * dx) + (dy * dy));
}
ll p2[50];

void solve() {
    int n;
    cin >> n;

    vector<ii> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    vector dp(n, vector<ld>(40, 1e18));
    dp[0] = vector<ld>(40, 0);

    // ate o checkpoint i usando j skips

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 40; j++) {
            for (int k = 0; k <= j && i - 1 - k >= 0; k++) {
                dp[i][j] = min(dp[i][j], dp[i - 1 - k][j - k] + dist2(a[i], a[i - 1 - k]));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        debug(i, dp[i]);
    }

    ld ans = dp[n - 1][0];
    for (int i = 1; i < 40; i++) {
        ans = min(ans, dp[n - 1][i] + p2[i - 1]);
    }

    cout << setprecision(20) << fixed << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 50; i++) {
        p2[i] = (1ll << i);
    }
    int TC = 0;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
            cerr << endl;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
