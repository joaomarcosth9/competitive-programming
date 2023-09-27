#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int x, k; cin >> x >> k;
    if(x % k){
        cout << 1 << '\n';
        cout << x << '\n';
    } else {
        cout << 2 << '\n';
        cout << 1 << " " << x-1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
