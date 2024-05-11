#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    ll a, b, r; cin >> a >> b >> r;
    ll best = abs(a - b);
    if (b > a) swap(a, b);
    debug(bin(a, 6));
    debug(bin(b, 6));
    for (int bit = 62; bit >= 0; bit--) {
        int A = (a >> bit) & 1;
        int B = (b >> bit) & 1;
        if (A == B) continue;
        ll px = 0;
        ll rr = r;
        for (int j = bit - 1; j >= 0; j--) {
            A = (a >> j) & 1;
            B = (b >> j) & 1;
            debug(j, A, B);
            if (A > B) {
                if (r >= (1ll << j)) {
                    px ^= (1ll << j);
                    r -= (1ll << j);
                    debug(bin(px));
                }
            }
        }
        r = rr;
        if (abs((a ^ px) - (b ^ px)) < best) {
            best = abs((a ^ px) - (b ^ px));
        }
        // px eh o melhor que deixa a > b
        if (r >= (1ll << bit)) {
            px = 0;
            px ^= (1ll << bit);
            r -= (1ll << bit);
            for (int j = bit - 1; j >= 0; j--) {
                A = (a >> j) & 1;
                B = (b >> j) & 1;
                if (B > A) {
                    if (r >= (1ll << bit)) {
                        px ^= (1ll << j);
                        r -= (1ll << j);
                    }
                }
            }
            if (abs((a ^ px) - (b ^ px)) < best) {
                best = abs((a ^ px) - (b ^ px));
            }
        }
        break;
    }
    cout << best << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
