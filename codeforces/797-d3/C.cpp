#include <iostream>
using namespace std;
const int MAX = 2e5 + 500;
int s[MAX];
int f[MAX];
int ans[MAX];
int n;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    ans[0] = f[0] - s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] >= f[i - 1]) {
            ans[i] = f[i] - s[i];
        } else {
            ans[i] = f[i] - f[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        solve();
    }
    return 0;
}
