#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

int solve() {
    int n, m; cin >> n >> m;
    int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
    if (xa >= xb) {
        return 0;
    }
    int diff = xb - xa;
    debug(diff);
    if (diff & 1) { // Alice makes the last move
        int moves = diff / 2;
        int min_alice = max(1, ya - moves - 1);
        int max_alice = min(m, ya + moves + 1);
        int min_bob = max(1, yb - moves);
        int max_bob = min(m, yb + moves);
        if (min_bob >= min_alice && max_bob <= max_alice) {
            return 1;
        }
        return 0;
    } else { // Bob makes the last move
        int moves = diff / 2;
        int min_alice = max(1, ya - moves);
        int max_alice = min(m, ya + moves);
        int min_bob = max(1, yb - moves);
        int max_bob = min(m, yb + moves);
        debug(min_alice, max_alice, min_bob, max_bob);
        if (min_alice >= min_bob && max_alice <= max_bob) {
            return 2;
        }
        return 0;
    }
    return 0;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        /* solve(); */
        int ret = solve();
        if (ret == 0) cout << "Draw" << endl;
        else if (ret == 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
