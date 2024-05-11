#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool sorted(int num) {
    int last = 100;
    while (num > 0) {
        if (num % 10 > last) return false;
        last = num % 10;
        num /= 10;
    }
    return true;
}

int first(int num) {
    while (num > 10) {
        num /= 10;
    }
    return num;
}

bool solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector dp(n, vector<int> (100));
    dp[0][a[0]] = 1;
    if (sorted(a[0])) dp[0][a[0] % 10] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= a[i]; j++) {
            dp[i][a[i]] |= dp[i - 1][j];
        }
        if (sorted(a[i])) {
            for (int j = 0; j <= first(a[i]); j++) {
                dp[i][a[i] % 10] |= dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        if (dp[n - 1][i]) return true;
    }
    return false;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
