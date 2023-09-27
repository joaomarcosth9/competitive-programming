#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m, b, s;
    cin >> m >> b >> s;
    vector<string> v(b);
    vector<int> da(b);
    for (auto &a : v) cin >> a;
    int res = 0;
    for (int i = 0; i < b; i++)
        if (v[i][m - 1] == '1') da[i] = 1;
    for (int j = 0; j < s; j++) {
        int d = 0;
        for (int i = 0; i < b; i++) {
            if (da[i] && v[i][j] == '1' && j != m - 1) d = 1;
        }
        res += d;
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}
