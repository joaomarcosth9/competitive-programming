#include <bits/stdc++.h>

#define _                                                                                                              \
    ios_base::sync_with_stdio(0);                                                                                      \
    cin.tie(0);
#define endl '\n'

using namespace std;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    if (s[0] == 'Y' || s[0] == 'y') {
        if (s[1] == 'E' || s[1] == 'e') {
            if (s[2] == 'S' || s[2] == 's') {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    _ int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++) {
        solve();
    }
    return 0;
}
