#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e5 + 5;
int dp[N];

bool dpp(int val) {
    if (dp[val] != -1) return dp[val];
    dp[val] = 0;
    for (int i = 0; i < (1 << 5); i++) {
        int pot = 1;
        int j = i;
        int num = 0;
        for (int k = 0; k < 5; k++) {
            if (i & (1 << k)) num += pot;
            pot *= 10;
        }
        if (num && val % num == 0) {
            if (dpp(val / num)) dp[val] = 1; 
        }
    }
    return dp[val];
}

bool solve() {
    int n; cin >> n;
    return dpp(n);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof (dp));
    int TC; cin >> TC;
    for (int i = 0; i < (1 << 5); i++) {
        int pot = 1;
        int j = i;
        int num = 0;
        for (int k = 0; k < 5; k++) {
            if (i & (1 << k)) num += pot;
            pot *= 10;
        }
        dp[num] = 1;
    }
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
