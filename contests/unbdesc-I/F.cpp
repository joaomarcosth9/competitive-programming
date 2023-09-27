#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif
typedef long long ll;

ll fib[100], pref[100];

ll rec(ll i, ll f){
    if(f == 0) return 0;
    if(f == 1) return 1;
    if(i == fib[f]) return fib[f-1];
    if(i <= fib[f-1]){
        return rec(i, f-1);
    }
    return fib[f-2] + rec(i - fib[f-1], f-2);
}

ll f(ll x){
    if(x == -1) return 0;
    if(x == 0) return 0;
    int it = 1;
    while(pref[it+1] <= x){
        it++;
    }
    ll curr = pref[it-1];
    ll idx = x - pref[it] + 1;
    curr += rec(idx, it+1);
    return curr;
}

ll fa(ll l, ll r){
    return f(r) - f(l-1);
}

ll fb(ll l, ll r){
    return (r - l + 1) - fa(l, r);
}

void solve(){
    ll l, r; cin >> l >> r;
    cout << fa(l, r) << " " << fb(l, r) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < 100; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    // pref[i] = fib[i+2] - 1;
    for(int i = 0; i < 98; i++){
        pref[i] = fib[i+2] - 1;
    }
    solve();
}
