#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 50;

int arr[MAX];

void solve() {
    int n;
    cin >> n;
    map<int, pair<int, int>> A;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    arr[n] = -1;

    int num = arr[0];
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (num == arr[i]) {
            count++;
        } else if (count == 1) {
            cout << -1 << '\n';
            return;
        } else {
            A[arr[i - 1]] = make_pair(i - count, i - 1);
            count = 1;
            num = arr[i];
        }
    }
    for (auto elm : A) {
        auto a = elm.second;
        count = a.second - a.first;
        cout << a.second + 1 << ' ';
        for (int i = 0; i < count; i++) {
            cout << a.first + i + 1 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}
