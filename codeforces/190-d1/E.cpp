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

const int maxn = 4005, maxk = 805;
int n, k;
int a[maxn][maxn];
int pref[maxn][maxn];
int dp[maxk][maxn];

int cost(int i, int j) {
    if (i > j) swap(i, j);
    return pref[j][j] + pref[i - 1][i - 1] - pref[j][i - 1] - pref[i - 1][j];
}

void solve(int l, int r, int L, int R, int i) {
    if (l > r) return;
    int mid = (l + r) / 2;
    int best = INT_MAX, where = -1;
    for (int j = L; j <= min(R, mid); j++) {
        int now = dp[i - 1][j - 1] + cost(j, mid);
        if (now < best) {
            best = now;
            where = j;
        }
    }
    dp[i][mid] = best;
    debug(i, mid, dp[i][mid]);
    solve(l, mid - 1, L, where, i);
    solve(mid + 1, r, where, R, i);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c; cin >> c;
            pref[i][j] = ((c - '0') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]);
        }
    }
    dp[0][0] = 0;
    /*
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= n; j++) {
            for (int l = j; l > 0; l--) {
                dp[i][j] = min(dp[i][j], dp[i - 1][l - 1] + cost(l, j));
            }
        }
    }
    */
    for (int i = 1; i <= k; i++) {
        solve(1, n, 1, n, i);
    }
    cout << (dp[k][n] >> 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, 0x3f, sizeof(dp));
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
