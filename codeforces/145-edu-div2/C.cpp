#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

void solve(){
    int n, k; cin >> n >> k;
    int pos = 1;
    vector<int> v(n, -1000);
    if(k > (n * (n + 1)) / 4){
        k = (n * (n + 1)) / 2 - k;
        pos = 0;
    }
    debug(k, pos);
    int ps = 0;
    int r = 1;
    int i;
    for(i = 0; i < n; i++){
        int pss = ps + r;
        if(pss <= k){
            v[i] = 2;
            ps = ps + r++;
        } else break;
    }
    debug(v);
    debug(ps);
    int falta = k - ps;
    debug(falta);
    if(falta){
        // i eh quantos tenho
        int tirar = i - falta;
        v[i] = -(tirar * 2 + 1);
    }
    for(i = 0; i < n; i++){
        cout << (pos ? v[i] : -v[i]) << ' ';
    }
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
