#include <bits/stdc++.h>

using namespace std;

int n, d, a;

void solve() {
    cin >> n >> d >> a;
    int out = (d - a) % n;
    if (out < 0) {
        out += n;
    }
    cout << out << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
