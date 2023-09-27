#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> res(5);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<string> t(5);
        bool eq = 0;
        for (int j = 0; j < 5; j++) {
            cin >> t[j];
            if (s == t[j]) {
                eq = 1;
                res[j] += 2;
            }
        }
        if (eq) continue;
        vector<int> dpp(5);
        int minn = 1e9;
        for (int j = 0; j < 5; j++) {
            int u = s.size();
            auto &r = t[j];
            int v = r.size();
            vector<vector<int>> dp(u + 1, vector<int>(v + 1, 0));
            for (int k = 1; k <= u; k++) dp[k][0] = k;
            for (int l = 1; l <= v; l++) dp[0][l] = l;
            for (int k = 1; k <= u; k++) {
                for (int l = 1; l <= v; l++) {
                    if (s[k - 1] == r[l - 1]) {
                        dp[k][l] = dp[k - 1][l - 1];
                    } else {
                        dp[k][l] = min({dp[k - 1][l], dp[k][l - 1], dp[k - 1][l - 1]}) + 1;
                    }
                }
            }
            dpp[j] = dp[u][v];
            minn = min(minn, dpp[j]);
        }
        for (int j = 0; j < 5; j++) {
            if (dpp[j] == minn) {
                res[j]++;
            }
        }
    }
    int mx = *max_element(begin(res), end(res));
    cout << setprecision(1) << fixed << double(mx) / 2.0 << '\n';
    vector<int> RES;
    for (int i = 0; i < 5; i++) {
        if (res[i] == mx) {
            RES.emplace_back(i + 1);
        }
    }
    for (int i = 0; i < (int)RES.size(); i++) {
        cout << RES[i] << " \n"[i == (int)RES.size() - 1];
    }
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
