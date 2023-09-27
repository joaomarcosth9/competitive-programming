#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &a : v) cin >> a;
    int cur = 0;
    int zz = 0;
    for (int j = n - 1; j >= 0; j--) {
        zz += v[j] == 0;
        if (v[j]) cur += zz;
    }
    int r1 = 0, r2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            v[i] = 1;
            int z = 0;
            for (int j = n - 1; j >= 0; j--) {
                z += v[j] == 0;
                if (v[j]) r1 += z;
            }
            v[i] = 0;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (v[i] == 1) {
            v[i] = 0;
            int z = 0;
            for (int j = n - 1; j >= 0; j--) {
                z += v[j] == 0;
                if (v[j]) r2 += z;
            }
            v[i] = 1;
            break;
        }
    }
    cout << max(cur, max(r1, r2)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
