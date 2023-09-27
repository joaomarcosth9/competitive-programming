#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    char c;
    string s;
    cin >> n >> c >> s;
    if (c == 'g') {
        cout << 0 << endl;
        return;
    }
    int res = 0;
    for (int i = 0; i < 2 * n;) {
        if (s[i % n] == c) {
            int tres = 0;
            for (int j = i; j < 2 * n; j++, i++) {
                if (s[j % n] == 'g') {
                    res = max(res, tres);
                    break;
                }
                tres++;
            }
        } else {
            i++;
        }
    }
    cout << res << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
