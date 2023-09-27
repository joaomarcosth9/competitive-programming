#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5;
int arr[MAX];
int sq[] = {0, 1, 1, 3, 1, 10, 3, 3, 1, 3, 10, 3, 3, 1, 3, 20, 1, 1, 3, 1};

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (arr[i] % 10 && arr[i] % 5)
            arr[i] = sq[arr[i] % 20];
        else if (arr[i] % 10 && arr[i] % 5 == 0)
            arr[i] = arr[i] + 5;
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
