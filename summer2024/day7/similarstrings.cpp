#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "ab" << endl;
        cout << "ba" << endl;
        return;
    }
    for (int i = 0; i < n; i++) cout << "a";
    for (int i = 0; i < n; i++) cout << "b";
    cout << endl;
    for (int i = 0; i < n - 1; i++) cout << "a";
    cout << "ba";
    for (int i = 0; i < n - 1; i++) cout << "b";
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
