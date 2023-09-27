#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;
const int MAX = 2e5 + 10;
int arr[MAX], n;

void solve() {
    map<int, int> dp;
    map<int, vector<int>> id;
    pair<int, int> res;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        dp[arr[i]] = dp[arr[i] - 1] + 1;
        id[dp[arr[i]]].push_back(i);
        if (dp[arr[i]] > res.first) {
            res.first = dp[arr[i]];
            res.second = i;
        }
    }
    // cout << res.first << ' ' << res.second << endl;
    for (int i = res.second; i > (res.second - res.first); i--) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}

int main() {
    _ int tsts;
    cin >> tsts;
    while (tsts--) solve();
    return 0;
}
