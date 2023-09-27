#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

auto ask(int p, int t) -> int {
    // b <= 1e9
    cout << "? " << (1 << (t - 1)) - p << " " << (1 << t) + (1 << (t - 1)) - p << endl;
    return cin >> p, p;
}

auto solve() -> void {
    int res = 0;
    int bit = 1;
    while (bit <= 30) {
        int g = ask(res, bit);
        if(g == (1 << bit)){
            res |= 1 << (bit - 1);
        }
        bit++;
    }
    cout << "! " << res << endl;
}

auto main() -> signed {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        while (TC--) solve();
    } else solve();
    return 0;
}
