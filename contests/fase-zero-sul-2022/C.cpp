#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
const int mod = 1e9 + 9;

void solve(){
    ll n, q; cin >> n >> q;
    ll nn = 0;
    for(int i = 0; i < n; i++){
        nn |= (1ll << i);
    }
    ll potn = 1;
    ll res = 0;
    ll i, j, cur = 0;
    while(q--){
        cur = 0;
        cin >> i >> j;
        if((i & -i) > (j & -j)) swap(i, j);
        if(i == 0){
            while(j != 0){
                j = (j * 2) & nn;
                cur += 1;
            }
        } else {
            while((i & -i) < (j & -j)) {
                debug(i, j);
                i = (i * 2) & nn;
                cur += 1;
            }
            if(i != j){

            }
            while(i != j){
                i = (i * 2) & nn;
                j = (j * 2) & nn;
                cur += 2;
            }
        }
        res = (res + cur * potn) % mod;
        potn = (potn * n) % mod;
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
