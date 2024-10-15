#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
using ld = double;

void solve() {
    int n; cin >> n;
    vector<ld> dp(n + 1), multis(n + 1), prob(n + 1);
    ld tot = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        prob[i] = x;
        tot += prob[i];
    }
    for (int i = 1; i <= n; i++) {
        prob[i] /= tot;
    }
    vector<ld> sum_probd(n + 1), sum_dpd(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            sum_probd[j] += prob[i];
        }
    }

    ld res = 0;

    dp[1] = (1.0 / (1.0 - prob[1]));

    multis[1] = dp[1] * prob[1];

    for (int i = 2; i <= n; i++) {
        dp[i] -= multis[1];
        sum_dpd[i] += dp[1];
    }

    for (int i = 2; i <= n; i++) {
        dp[i] += (sum_dpd[i] * sum_probd[i]);

        multis[i] = dp[i];
        dp[i] /= (1.0 - sum_probd[i]);

        multis[i] += dp[i] * sum_probd[i];

        for (int j = i + i; j <= n; j += i) {
            dp[j] -= multis[i];
            sum_dpd[j] += dp[i];
        }

    }

    for (int i = 1; i <= n; i++) {
        res += dp[i];
    }

    cout << setprecision(10) << fixed << res - 1 << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
