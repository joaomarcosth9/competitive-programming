#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    long long n, m; cin >> n >> m;
    int fn = 0, fm = 0;
    int nn = n, mm = m;
    while(nn % 3 == 0){
        fn++;
        nn /= 3;
    }
    while(mm % 3 == 0){
        fm++;
        mm /= 3;
    }
    int t = 0;
    while(fn > fm){
        n /= 3;
        fn--;
        t++;
    }
    debug(n, m);
    debug(fn, fm);
    t++;
    while(t--){
        if(n == m){
            cout << "YES" << '\n';
            return;
        }
        n *= 2;
    }
    cout << "NO" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
