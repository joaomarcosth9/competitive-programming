#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n';

using namespace std;

const int MAX = 1e5 + 10;

int dp[MAX];
int arr[MAX];
int n, k;

// recursive
int dpp(int p) {
    if (dp[p] != -1) return dp[p];
    int menor = dpp(p - 1) + abs(arr[p] - arr[p - 1]);
    for (int i = 1; i <= k && p - i >= 0; i++) {
        int poss = dpp(p - i) + abs(arr[p] - arr[p - i]);
        menor = min(menor, poss);
    }
    dp[p] = menor;
    return dp[p];
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < MAX; i++) {
        dp[i] = INT_MAX;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // iterative
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k && i - j >= 0; j++) {
            int dis = abs(arr[i] - arr[i - j]);
            dp[i] = min(dp[i], dis + dp[i - j]);
        }
    }

    cout << dp[n - 1] << endl;
}

int main() {
    _ solve();
    return 0;
}
