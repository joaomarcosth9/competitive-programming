#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
int a, b, c, x, y;

void solve() {
    cin >> a >> b >> c >> x >> y;
    if (a >= x) {
        if (b >= y) {
            cout << "YES" << endl;
            return;
        } else {
            // y > b
            c -= (y - b);
            if (c >= 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    } else {
        // x > a
        c -= (x - a);
        if (c >= 0) {
            if (b + c >= y) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
            return;
        }
    }
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
