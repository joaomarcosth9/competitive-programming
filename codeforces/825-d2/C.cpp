#include <bits/stdc++.h>
using namespace std;
int temtestcase = 1;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
#define int long long

const int mx = 2.1e5;
int n, arr[mx], gd[mx];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        /* arr[i] = min(arr[i], i+1); */
    }
    vector<int> res(n + 1);
    int ress = 0;
    for (int i = 1; i <= n; i++) {
        res[i] = min(res[i - 1] + 1, arr[i - 1]);
        ress += res[i];
    }
    cout << ress << endl;
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    for (int Testcase = 1; Testcase <= tsts; Testcase++) {
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
