#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5;
int arr[MAX];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (arr[i] % 10)
            arr[i] = (arr[i] + arr[i] % 10) % 20;
        else if (arr[i] % 10 && arr[i] % 5 == 0)
            arr[i] += 5;
    }
    for (int i = 0; i < n; i++) {
        while (1) {
            if (arr[i] % 10 == 0) {
                arr[i] -= 5;
                break;
            } else if (arr[i] % 10 == 1 && arr[i] > 10) {
                arr[i] -= 5;
            } else if (arr[i] % 10 == 1 && arr[i] < 10) {
                break;
            } else if (arr[i] % 10 == 3 && arr[i] > 10) {
                arr[i] -= 5;
            } else if (arr[i] % 10 == 3 && arr[i] < 10) {
                break;
            } else if (arr[i] % 10 == 7 && arr[i] < 10) {
                arr[i] = 3;
            } else if (arr[i] % 10 == 7 && arr[i] > 10) {
                arr[i] -= 9;
            } else if (arr[i] % 10 == 9 && arr[i] < 10) {
                arr[i] = 3;
            } else if (arr[i] % 10 == 9 && arr[i] > 10) {
                arr[i] -= 11;
            } else if (arr[i] % 2 == 0) {
                arr[i] -= (arr[i] % 10) / 2;
            } else {
                arr[i] += arr[i] % 10;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
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
