#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    double n;
    cin >> n;
    n *= 10;
    int aaa = round(n);
    double ne = (500 - 6 * aaa) / 4;
    cout << setprecision(1) << fixed;
    cout << ne / 10 << endl;
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
