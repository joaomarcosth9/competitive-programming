#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n';

using namespace std;

const int MAX = 1e5 + 10;

int dp[MAX];
int arr[MAX];

// recursive
int dpp(int p) {
    if (p == 1) {
        dp[p] = abs(arr[1] - arr[0]);
        return dp[p];
    } else if (p == 0) {
        return 0;
    }
    if (dp[p] != -1) return dp[p];
    dp[p] = min(dpp(p - 1) + abs(arr[p] - arr[p - 1]), dpp(p - 2) + abs(arr[p] - arr[p - 2]));
    return dp[p];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < MAX; i++) {
        dp[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    // iterative
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
    }

    cout << dp[n - 1] << endl;
}

int main() {
    _ solve();
    return 0;
}
