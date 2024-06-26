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
    srand(time(0));
    int n = 6;
    string s(n, 'a');
    for (int i = 0; i < n; i++) {
        s[i] = vector<char>{'a', 'b', 'c'}[rand() % 3];
    }
    int q = 8;
    cout << s << endl;
    cout << q << endl;
    for (int i = 0; i < q; i++) {
        int l = rand() % n, r = rand() % n;
        if (l > r) swap(l, r);
        string t = s.substr(l, r - l + 1);
        cout << t << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
