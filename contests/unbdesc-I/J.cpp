#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n; cin >> n;
    long long m; cin >> m;
    vector<long long> v(n);
    for(auto& u : v) cin >> u;
    long long sum = accumulate(begin(v), end(v), 0ll);
    long long q = m / sum;
    long long res = q * n;
    m = m % sum;
    debug(res);
    for(int i = 0; i < n; i++){
        if(m > 0){
            m -= v[i];
            res++;
        } else break;
    }
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
