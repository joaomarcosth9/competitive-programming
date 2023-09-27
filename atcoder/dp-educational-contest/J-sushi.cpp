#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long double ld;
int n;
bool comp[301][301][301];
ld dp[301][301][301];

ld dpp(int c1, int c2, int c3){
    auto &mydp = dp[c1][c2][c3];
    if(comp[c1][c2][c3]) return mydp;
    comp[c1][c2][c3] = 1;
    if(c1 == 1 && c2 == 0 && c3 == 0) {
        mydp = n;
        return mydp;
    }
    int c0 = n - (c1 + c2 + c3);
    mydp += ld(c0) / n;
    if(c1) mydp += ld(c1) / n * (dpp(c1 - 1, c2, c3) + 1);
    if(c2) mydp += ld(c2) / n * (dpp(c1 + 1, c2 - 1, c3) + 1);
    if(c3) mydp += ld(c3) / n * (dpp(c1, c2 + 1, c3 - 1) + 1);
    if(c0) mydp /= (1.0 - (ld(c0) / n));
    return mydp;
}

void solve() {
    cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
    int c0 = 0, c1 = count(begin(v), end(v), 1), c2 = count(begin(v), end(v), 2), c3 = count(begin(v), end(v), 3);
    debug(c0, c1, c2, c3);
    cout << setprecision(15) << fixed << dpp(c1, c2, c3) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
