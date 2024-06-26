#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

void solve() {
    int n = 5, m = 2;
    cout << n << " " << m << endl;
    string s(n, '1');
    vector<char> poss = {'0', '1', '?'};
    for (int i = 0; i < n; i++) {
        s[i] = poss[uniform(0, 2)];
    }
    cout << s << endl;
    for (int i = 0; i < m; i++) {
        int l = uniform(0, n - 1), r = uniform(0, n - 1);
        if (l > r) swap(l, r);
        cout << l + 1 << " " << r + 1 << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
