#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    vector<int> v(n+1);
    v[1] = 12;
    v[2] = 18;
    for(int i = 3; i <= n; i++){
        v[i] = v[i-2] + 4 * i + 5;
    }
    cout << v[n] << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
