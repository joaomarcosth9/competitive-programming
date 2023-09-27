#include <bits/stdc++.h>

using namespace std;

void solve() {
    int c, l;
    cin >> c >> l;
    cout << (c * l + (c - 1) * (l - 1)) << endl;
    cout << 2 * (c + l - 2) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
