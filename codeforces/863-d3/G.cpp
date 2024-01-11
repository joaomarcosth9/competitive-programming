#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int mod = (int)1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

const int N = 5005;
int n, k, best, res, a[N], freq[N], dp[N][N], pref_dp[N][N], all[N][N];
vector<int> where[N];

void solve() {
    cin >> n >> k;

    best = res = 0;
    memset(a, 0, (n + 1) * sizeof *a);
    memset(freq, 0, (n + 1) * sizeof *freq);
    memset(dp, 0, (n + 1) * (n + 1) * sizeof *dp);
    memset(pref_dp, 0, (n + 1) * (n + 1) * sizeof *pref_dp);
    memset(all, 0, (n + 1) * (n + 1) * sizeof *all);
    for (int i = 0; i <= n; i++) where[i].clear();

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        if (freq[a[i]] == k) {
            best++;
            memset(freq, 0, (n + 1) * sizeof *freq);
        }
    }

    debug(best);

    dp[n][0] = 1;
    pref_dp[n][0] = 1;
    for (int i = 1; i <= n; i++) {
        all[a[i]][0] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        where[a[i]].emplace_back(i);

        debug(i, a[i], where[a[i]]);
        if ((int)where[a[i]].size() >= k) {
            int idx = where[a[i]].end()[-k] + 1;
            debug(idx);
            for (int j = 1; j <= n; j++) {
                if (j > 1) add(all[a[i]][j - 1], pref_dp[idx][j - 1]);
                add(dp[i][j], all[a[i]][j - 1]);
                debug(j, dp[i][j], pref_dp[idx][j - 1]);
            }
        }

        for (int j = 0; j <= n; j++) {
            add(pref_dp[i][j], pref_dp[i + 1][j]);
            add(pref_dp[i][j], dp[i][j]);
            debug(j, pref_dp[i][j]);
        }

    }
    
    for (int i = 0; i < n; i++)
        add(res, dp[i][best]);

    cout << (best ? res : 1) << endl;

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
