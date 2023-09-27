#include <bits/stdc++.h>

using namespace std;

int n;

void solve() {
    cin >> n;
    if (n <= 800) {
        cout << 1 << '\n';
    } else if (n <= 1400) {
        cout << 2 << '\n';
    } else if (n <= 2000) {
        cout << 3 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
