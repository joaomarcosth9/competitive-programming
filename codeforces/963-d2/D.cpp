#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> vals;
    for (int i = 0; i < n; i++) {
        vals.push_back(a[i]);
    }

    sort(begin(vals), end(vals));
    vals.erase(unique(begin(vals), end(vals)), end(vals));

    int l = 0, r = (int)vals.size() - 1;

    vector<int> b(n), pref(n + 1);
    vector<vector<int>> dp(n + 1, vector<int> (2));

    auto query = [&](int L, int R) {
        return pref[R] - pref[L - 1];
    };

    int n_left = n % k;
    if (n_left == 0) n_left = k;
    int need = (n_left + 2) / 2;
    int taken = n - n_left;

    debug(n_left, need, taken);

    while (l <= r) {
        for (int i = 0; i <= n; i++) {
            dp[i][0] = dp[i][1] = pref[i] = 0;
        }
        int mid = (l + r) / 2;
        int cnt_one = 0;
        for (int i = 0; i < n; i++) {
            b[i] = (a[i] >= vals[mid]);
            if (b[i] == 1) {
                cnt_one++;
            }
        }
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + !b[i - 1];
        }
        debug(b);
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= k) {
                dp[i][0] = dp[i - k][0] + query(i - k + 1, i);
                if (i > k) dp[i][1] = dp[i - k][1] + query(i - k + 1, i);
            }
            dp[i][1] = max({dp[i][1], dp[i - 1][0], dp[i - 1][1]});
        }
        // dp[n][1] -> maximo de zeros que consegui pegar skippando pelo menos uma vez
        int ones_taken = (taken - dp[n][1]);
        int ones_left = cnt_one - ones_taken;
        if (ones_left >= need) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << vals[r] << endl;
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
