#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    int r, d, c;
    cin >> r >> d >> c;
    // d2 = r2 + r2 - 2r2 cos a
    // d2 = 2r2 - 2r2 cos a
    // d2 = 2r2 (1 - cos a)
    // d2/2r2 = 1 - cos a
    // cos a = 1 - d2/2r2
    // cos a = d2 /(2- 2r2)
    double ang = acos(1 - (pow(d, 2) / (2 * pow(r, 2))));
    double arc = ang * r;
    if (c >= 2 * arc) {
        cout << "possivel" << endl;
    } else {
        cout << "impossivel" << endl;
    }
}

int main() {
    _ solve();
    return 0;
}
