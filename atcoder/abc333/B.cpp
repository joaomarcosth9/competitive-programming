#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

bool solve() {
    char s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;
    s1 -= 'A';
    s2 -= 'A';
    t1 -= 'A';
    t2 -= 'A';
    int next[5] = {1, 2, 3, 4, 0};
    int prev[5] = {4, 0, 1, 2, 3};
    bool one = s2 == next[s1] || s2 == prev[s1];
    bool two = t2 == next[t1] || t2 == prev[t1];
    return one == two;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
