#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c;
    d = a - (b + c);
    int maior[3] = {b, c, d};
    cout << *max_element(maior, maior + 3) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
