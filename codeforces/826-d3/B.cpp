#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    if (n == 3) {
        cout << -1 << endl;
        return;
    }
    if (n & 1) {
        cout << n - 1 << ' ' << n << ' ';
        for (int i = 1; i < n - 1; i++) {
            cout << i << ' ';
        }
    } else {
        for (int i = n; i > 0; i--) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
