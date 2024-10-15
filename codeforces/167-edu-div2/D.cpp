#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAX = 1e6 + 5;
int n, m;
int a[MAX], b[MAX], c[MAX];
int diff[MAX], pref[MAX];

int dp[MAX];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        diff[i] = a[i] - b[i];
        pref[a[i]] = min(pref[a[i]], diff[i]);
    }
    for (int i = 1; i < MAX; i++) {
        pref[i] = min(pref[i], pref[i - 1]);
    }

    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    for (int i = 1; i < MAX; i++) {
        dp[i] = dp[i - 1];
        int back = pref[i];
        if (back <= i) dp[i] = max(dp[i], 2 + dp[i - back]);
    }

    ll res = 0;
    for (int i = 0; i < m; i++) {
        if (c[i] >= MAX) {
            int back = pref[MAX - 1];
            int diff = c[i] - (MAX - 1);
            int qnt = diff / back;
            if (diff % back) {
                qnt++;
            }
            int real_back = qnt * back;
            debug(c[i], back, qnt, real_back);
            res += dp[c[i] - real_back] + 2LL * (qnt);
        } else {
            res += dp[c[i]];
        }
    }

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(pref, 0x3f, sizeof pref);
    solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
}