#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

int arr[2005];

void solve() {
    int n;
    cin >> n;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + arr[i];
    }
    int res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int tsum = pref[i];
        int maxx = i;
        int last = i;
        for (int j = i + 1; j <= n; j++) {
            if (j == n && pref[j] - pref[last] != tsum) {
                maxx = INT_MAX;
                continue;
            }
            if (pref[j] - pref[last] == tsum) {
                maxx = max(maxx, j - last);
                last = j;
            }
            if (pref[j] - pref[last] > tsum) {
                maxx = INT_MAX;
                break;
            }
        }
        res = min(res, maxx);
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
