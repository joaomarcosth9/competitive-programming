#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5 + 10;
int arr[MAX];

void solve() {
    int n;
    cin >> n;
    map<int, int> F;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        if (F[arr[i]]) {
            cout << n - j << endl;
            return;
        }
        F[arr[i]]++;
    }
    cout << 0 << endl;
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
