#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    long long n;
    long long i = 1, res = 1, l = 1, r = 1; cin >> n;
    for(int it = 0; it < 9; it++){
        r *= 10ll;
    }
    while(l <= r){
        i = l + ((r-l)>>1ll);
        if(i * i < n){
            l = i+1;
        } else {
            res = i;
            r = i-1;
        }
    }
    long long ress = res;
    cout << ress-1 << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}

