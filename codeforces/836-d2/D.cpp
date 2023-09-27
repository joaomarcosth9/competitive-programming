#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve() {
    int n;
    cin >> n;
    int gap = n << 1;
    int a1 = 1, a2 = a1 + gap;
    cout << a1 << " " << a2 << endl;
    long long minn = (((a1 + a1 + n - 2) * (n - 1)) >> 1) + a2;
    long long maxx = a1 + (((a2 - (n - 2) + a2) * (n - 1)) >> 1);
    cout << minn << " " << maxx << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
