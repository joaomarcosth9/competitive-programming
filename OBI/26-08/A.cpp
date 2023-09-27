#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    int n;
    cin >> n;
    int e = min(n, 5);
    int d = max(0, n - 5);
    if (!e) cout << "*";
    while (e--) {
        cout << "I";
    }
    cout << endl;
    if (!d) cout << "*";
    while (d--) {
        cout << "I";
    }
    cout << endl;
}

int main() {
    _ solve();
    return 0;
}
