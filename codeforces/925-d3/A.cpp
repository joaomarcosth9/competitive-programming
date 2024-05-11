#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

string solve() {
    int n; cin >> n;
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= 26; j++) {
            for (int k = 1; k <= 26; k++) {
                if ((i + j + k) == n) {
                    string s;
                    char c = 'a' + i - 1;
                    s.push_back(c);
                    c = 'a' + j - 1;
                    s.push_back(c);
                    c = 'a' + k - 1;
                    s.push_back(c);
                    return s;
                }
            }
        }
    }
    return "";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
