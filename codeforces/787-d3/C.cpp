#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;
string s;

void solve() {
    cin >> s;
    int len = s.size();
    int res = 0;
    int lo = -1;
    int fz = len;
    for (int i = 0; i < len; i++) {
        if (s[i] == '1') {
            res = 1;
            lo = i;
        }
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            res++;
            fz = i;
            break;
        }
    }
    res += fz - lo - 1;
    cout << res << endl;
}

int main() {
    _ int tscf;
    cin >> tscf;
    while (tscf--) solve();
    return 0;
}
