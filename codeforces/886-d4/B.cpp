#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int res = -1, best = 0;
        for (int i = 1; i <= n; i++) {
            int a, b; cin >> a >> b;
            if (a > 10) continue;
            if (b > best) {
                best = b;
                res = i;
            }
        }
        cout << res << "\n";
    }
}
