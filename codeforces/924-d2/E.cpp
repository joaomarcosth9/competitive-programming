#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;
const int INF = 1e18;

int gauss(int n) {
    return (n * (n + 1)) / 2;
}

void solve() {
    int n, x, y, s; cin >> n >> x >> y >> s;
    int z = x % y;
    vector<int> dp(s + 1, INF), par(s + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= s; i++) {
        for (int j = 1; gauss(j) <= i; j++) {
            if (dp[i - gauss(j)] + j + 1 < dp[i]) {
                dp[i] = dp[i - gauss(j)] + j + 1;
                par[i] = j;
            }
        }
    }
    debug(z);
    for (int L = 1; L <= n; L++) {
        int S = s - (x * L) - y * gauss(L - 1);
        int R = n - L;
        int oth = R * z;
        S = S - oth;
        if (S % y) continue;
        if (S < 0) continue;
        debug(S, L, R, dp[S], oth);
        S = S / y;
        if (dp[S] <= R) {
            cout << "YES" << endl;
            vector<int> res;
            res.push_back(0);
            for (int j = 1; j <= L; j++) {
                res.push_back(x + (j - 1) * y);
            }
            for (int j = L + 1; j <= n; j++) {
                res.push_back(z);
            }
            int j = n;
            while (j > L && S > 0) {
                int i = j;
                int val = par[S];
                while (val >= 0) {
                    res[i] += val * y;
                    val--;
                    i--;
                }
                S -= gauss(par[S]);
                j = i;
            }
            assert(S == 0);
            for (int i = 1; i <= n; i++) cout << res[i] << " ";
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
