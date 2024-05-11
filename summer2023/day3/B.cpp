#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1.1e5;
int arr[MAX];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] += b;
    }
    long long ss = 0;
    for (int i = 0; i < MAX; i++) {
        ss += arr[i];
        if (ss >= k) {
            cout << i << endl;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
