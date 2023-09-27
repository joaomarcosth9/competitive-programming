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
#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
const int maxn = 1e3 + 1;
int dp[maxn][maxn][1 << 5];
int inf;
int n;

int dpp(int s1, int s2, int mask) {
    if (s1 > 5) s1 = 0;
    if (s2 > 5) s2 = 0;
    if (s1 < 0 || s2 < 0) return inf;
    if (dp[s1][s2][mask] != inf) return dp[s1][s2][mask];
    int val = s1 + s2;
    for (int i = 0; i < 5; i++) {
        if (mask & (1 << i)) continue;
        int L = dpp(s1 - i - 1, s2, mask | (1 << i));
        int R = dpp(s1, s2 - i - 1, mask | (1 << i));
        val = min({val, L, R});
    }
    return dp[s1][s2][mask] = val;
}

void solve() {
    int k, e;
    cin >> n >> k >> e;
    inf = dp[0][0][0];
    int d = n - k - e;
    if (e > 5 && d > 5) {
        cout << "0" << endl;
        return;
    }
    cout << dpp(e, d, (k <= 5 ? (1 << (k - 1)) : 0)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    memset(dp, 0x3f, sizeof dp);
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
