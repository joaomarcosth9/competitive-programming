#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
ll MOD = 1;

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}
 
ll bpow(ll b, ll e) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) {
            res = mul(res, b);
        }
        b = mul(b, b);
        e >>= 1;
    }
    return res;
}

ll inv(ll b) {
    return bpow(b, MOD - 2);
}

ll divi(ll a, ll b) {
    return mul(a, inv(b));
}

const int N = 1050, K = N;

ll p2[N], fat[N], ifat[N];

ll dp[N][K], sb[N][K], psb[N][K];

void solve() {
    int n, k;
    cin >> n >> k >> MOD;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }

    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = mul(2, p2[i - 1]);
    }

    fat[0] = 1;
    for (int i = 1; i < N; i++) {
        fat[i] = mul(i, fat[i - 1]);
    }

    ifat[N - 1] = inv(fat[N - 1]);
    for (int i = N - 1; i > 0; i--) {
        ifat[i - 1] = mul(i, ifat[i]);
    }

    for (int i = 0; i <= k; i++) {
        sb[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int len = p2[i] - 1;
            if (i <= 9) {
                sb[i][j] = mul(fat[j + len - 1], mul(ifat[j], ifat[len - 1]));
            } else {
                sb[i][j] = 1;
                for (int up = j + len - 1, qt = 1; qt <= j; up = add(up, -1), qt++) {
                    sb[i][j] = mul(sb[i][j], up);
                }
                sb[i][j] = mul(sb[i][j], ifat[j]);
            }
            psb[i][j] = sb[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            psb[i][j] = add(psb[i][j], psb[i][j - 1]);
        }
    }

    for (int i = 0; i <= k; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            for (int a = 1; a <= j; a++) {
                dp[i][j] = add(dp[i][j], mul(dp[i - 1][a], psb[i - 1][min(a - 1, j - a)]));
            }
        }
    }

    cout << mul(dp[n][k], p2[n - 1]) << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
