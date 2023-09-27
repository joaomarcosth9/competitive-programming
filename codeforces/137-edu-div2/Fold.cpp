#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 3e3 + 5, mod = 998244353;
int n;
long long dp[maxn][maxn][2];
pair<int, int> s[maxn];

struct node {
    long long t, nt;
    node(int t, int nt) : t(t), nt(nt){};
    node(node &l, node &r) {
        t = ((2 * l.t * r.t % mod) + (2 * l.t * r.nt % mod) + (2 * l.nt * r.t % mod)) % mod;
        nt = ((l.t * r.t % mod) + (l.t * r.nt % mod) + (l.nt * r.t % mod) + (3 * l.nt * r.nt % mod)) % mod;
    }
};

vector<node> seg;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    // dp[i][j][k] numero de formas de escolher os operadores ate o conjunto i incluindo o valor j na resposta (se k ==
    // 1)
    auto [l, r] = s[0];
    for (int i = 0; i < maxn; i++) {
        if (i >= l && i <= r) {
            dp[0][i][1] = 1;
        } else {
            dp[0][i][0] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < maxn; j++) {
            if (j >= s[i].first && j <= s[i].second) {
                // j esta no conjunto s[i]
                /* matriz do 1 */
                /* [2 2] */
                /* [1 1] */
                dp[i][j][1] = ((dp[i - 1][j][1] * 2 % mod) + (dp[i - 1][j][0] * 2 % mod)) % mod;
                dp[i][j][0] = (dp[i - 1][j][1] + dp[i - 1][j][0]) % mod;
            } else {
                // j NAO esta no conjunto s[i]
                /* matriz do 0 */
                /* [2 0] */
                /* [1 3] */
                dp[i][j][1] = (dp[i - 1][j][1] * 2 % mod) % mod;
                dp[i][j][0] = (dp[i - 1][j][1] + (dp[i - 1][j][0] * 3 % mod)) % mod;
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < maxn; i++) {
        if (i <= 10) {
            db(i, dp[n - 1][i][1]);
            /* db(i, dp[n-1][i][0]); */
        }
        res += dp[n - 1][i][1];
    }
    res %= mod;
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
