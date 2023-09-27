#include <bits/stdc++.h>

using namespace std;

int temtestcase = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
typedef long long ll;

void solve() {
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    // l <= a,b <= r
    // tem que chegar de a em b
    // a tem q mudar no minimo x

    if (abs(a - b) >= x) {
        cout << 1 << endl;
        return;
    } else if (a == b) {
        cout << 0 << endl;
        return;
    }

    int res = 100;

    if (a - x >= l) {
        if (abs(l - b) >= x) {
            res = min(res, 2);
        } else if (abs(l - r) >= x && abs(r - b) >= x) {
            res = min(res, 3);
        }
    }
    if (a + x <= r) {
        if (abs(r - b) >= x) {
            res = min(res, 2);
        } else if (abs(l - r) >= x && abs(l - b) >= x) {
            res = min(res, 3);
        }
    }
    cout << (res == 100 ? -1 : res) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
