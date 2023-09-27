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

const int maxn = 405;
ll a[maxn];
ll dp[maxn][maxn];
ll sum[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k <= j; k++) sum[i][j] += a[k];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) dp[i][j] = (ll)1e18;
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = sum[i][i + 1];
    }
    for (int s = 3; s <= n; s++) {
        for (int l = 0; l + s - 1 < n; l++) {
            int r = l + s - 1;
            dp[l][r] = min(dp[l][r], dp[l + 1][r] + sum[l][r]);
            dp[l][r] = min(dp[l][r], dp[l][r - 1] + sum[l][r]);
            for (int k = l; k < r; k++) {
                // a[k] -> dp[l][k - 1], dp[k + 1][r]
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[l][r]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
