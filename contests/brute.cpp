#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

int lis(vector<int> a) {
    vector<int> dp(a.size(), 1);
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    if (*max_element(dp.begin(), dp.end()) > 2) return -1;
    for (int i = 0; i < (int)a.size(); i++) {
        if (dp[i] == 2) return i;
    }
    return (int)a.size();
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pos(n + 1);
    do {
        if (lis(a) != -1) pos[lis(a)]++;
    } while (next_permutation(a.begin(), a.end()));
    debug(n, pos);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
