#include <bits/stdc++.h>
#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

const int MAX = 2e5 + 50;
int arr[MAX], pref[MAX], suff[MAX];
map<int, int> freq;

void solve() {
    int n, s;
    cin >> n >> s;
    memset(arr, 0, n + 4);
    memset(pref, 0, n + 4);
    freq.clear();

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    if (sum < s) {
        cout << -1 << endl;
        return;
    }

    vector<int> pf(sum + 1);
    vector<int> sf(sum + 1);
    int ii = 1, jj = sum;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 1) {
            pf[ii] = i;
            sf[jj] = n - i + 1;
            ii++, jj--;
        }
    }

    int res = INT_MAX;
    int tirar = sum - s;
    for (int i = 0; i <= tirar; i++) {
        int tres = (pf[i] + sf[tirar - i]);
        res = min(res, tres);
    }
    cout << res << endl;
}

int main() {
    _ int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
