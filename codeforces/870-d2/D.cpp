#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<ll> v(n);
    for(auto& a : v) cin >> a;
    vector<ll> pf(n), sf(n);
    pf[0] = v[0];
    for(int i = 1; i < n; i++){
        pf[i] = max(v[i] + i, pf[i-1]);
    }
    sf[n-1] = v[n-1] - (n-1);
    for(int i = n-2; i >= 0; i--){
        sf[i] = max(v[i] - i, sf[i+1]);
    }
    ll res = INT_MIN;
    for(int i = 1; i < n-1; i++){
        res = max(res, pf[i-1] + v[i] + sf[i+1]);
    }
    cout << res << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
