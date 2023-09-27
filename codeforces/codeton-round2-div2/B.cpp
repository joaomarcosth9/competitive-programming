#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5 + 10;
int arr[MAX];

void solve() {
    int n, x;
    cin >> n >> x;
    cin >> arr[0];
    int a = arr[0];
    int res = 0;
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        if (abs(arr[i] - a < x)) {
            a = arr[i];
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
