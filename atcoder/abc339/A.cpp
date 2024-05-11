#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    string s; cin >> s;
    int n = int(s.size());
    string t;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '.') {
            reverse(t.begin(), t.end());
            cout << t << endl;
            return;
        }
        t.push_back(s[i]);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
