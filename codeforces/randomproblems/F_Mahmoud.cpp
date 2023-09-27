#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int maxn = 1e5 + 5, mod = 1e9 + 7;

vector<int> basis[maxn];
int sz[maxn];

void insertVector(int id, int u){
    for(int i = 0; i < 21; i++){
        if(u & (1 << i)){
            if(!basis[id][i]){
                basis[id][i] = u;
                sz[id]++;
            }
            u ^= basis[id][i];
        }
    }
}

bool testVector(int id, int u){
    for(int i = 0; i < 21; i++){
        if(u & (1 << i)){
            if(!basis[id][i]){
                return 0;
            }
            u ^= basis[id][i];
        }
    }
    return 1;
}

long long binpow(long long b, long long e){
    long long res = 1;
    while(e){
        if(e & 1) res = res * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return res;
}

void solve(){
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++){
        if(i == 0) basis[i].resize(21);
        else basis[i] = basis[i-1], sz[i] = sz[i-1];
        int u; cin >> u;
        insertVector(i, u);
    }
    while(q--){
        int l, x; cin >> l >> x;
        --l;
        if(testVector(l, x)){
            int res = 1;
            cout << binpow(2, l+1 - sz[l]) << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
