#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    int og = (n + 1) + (n % 2 == 0);
    debug(og);
    cout << max(0, og / 2 - 1) << " " << (og / 2) + (n % 2 == 0) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}

