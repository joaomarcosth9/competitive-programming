#include <iostream>

using namespace std;

const int MAX = 5e4 + 500;
int a[MAX];
int b[MAX];

void solve() {
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < size; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < size; i++) {
        if (a[i] < b[i]) {
            cout << "NO\n";
            return;
        }
    }
    int diff;
    int achou_diff = 0;
    for (int i = 0; i < size; i++) {
        if (b[i] != 0) {
            diff = a[i] - b[i];
            achou_diff++;
            break;
        }
    }
    if (!achou_diff) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        a[i] -= diff;
        if (a[i] < 0) {
            a[i] = 0;
        }
    }
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
