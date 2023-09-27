#include <bits/stdc++.h>

using namespace std;

int testcases = 0;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;

void solve() {
    int n;
    cin >> n;
    int res = 1;
    int cur;
    cin >> cur;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        if (p != cur) {
            res++;
        }
        cur = p;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
