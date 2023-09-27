#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve() {
    int n;
    cin >> n;
    if ((n & 1) == 0) {
        cout << "1 3 ";
        n -= 2;
    }
    for (int i = 0; i < n; i++) {
        cout << 2 << ' ';
    }
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
