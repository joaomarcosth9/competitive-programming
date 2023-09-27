#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ok = 1;
    for (int i = 0; i < min(23, n); i++) {
        int okk = 0;
        for (int j = i + 2; j >= 2; j--) {
            if (v[i] % j) {
                okk = 1;
                break;
            }
        }
        ok &= okk;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
