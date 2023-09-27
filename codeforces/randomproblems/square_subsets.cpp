#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
const int mod = 1e9 + 7;

int basis[21];
int sz = 0;

void insertVector(int u){
    for(int i = 0; i < 21; i++){
        if((u & (1 << i)) == 0) continue;
        if(!basis[i]) {
            basis[i] = u;
            sz++;
            return;
        }
        u ^= basis[i];
    }
}

void solve(){
    int n; cin >> n;
    vector<int> primes;
    for(int i = 2; i <= 70; i++){
        bool prime = 1;
        for(int j = 2; j < i; j++){
            if(i % j == 0) prime = 0;
        }
        if(prime) primes.emplace_back(i);
    }
    vector<int> v(n);
    for(int &u : v) {
        cin >> u;
    }
    vector<int> mask(71);
    for(int i = 1; i <= 70; i++){
        int u = i;
        int _mask = 0;
        for(int j = 0; j < (int)primes.size(); j++){
            while(u % primes[j] == 0){
                _mask ^= (1 << j);
                u /= primes[j];
            }
        }
        mask[i] = _mask;
    }
    for(int u : v){
        insertVector(mask[u]);
    }
    debug(n, sz);
    int res = 1;
    for(int i = 0; i < n-sz; i++){
        res = 2ll * res % mod;
    }
    cout << res - 1 << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}

