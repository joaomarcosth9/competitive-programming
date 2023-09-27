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

const int mod = 1e9 + 7, maxn = 21;

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int mat[maxn + 1][maxn + 1];
int dp[1 << maxn][maxn + 1];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) mat[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> mat[i][j];
    }

    dp[0][0] = 1;
    for (int i = 0; i < (1 << n) - 1; i++) {
        int N = __builtin_popcount(i);
        for (int j = 0; j < n; j++) {
            if (i & (1 << j) || mat[j + 1][N + 1] != 1) continue;
            add(dp[i | (1 << j)][N + 1], dp[i][N]);
        }
    }

    cout << dp[(1 << n) - 1][n] << endl;
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
