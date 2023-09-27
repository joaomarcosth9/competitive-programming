#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const long long maxn = 3e5+5, mod = 998244353;

typedef array<array<long long, 2>, 2> mat;
void mul(mat& a, mat& b, mat& c){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            c[i][j] = 0;
            for(int k = 0; k < 2; k++){
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j])) % mod;
            }
        }
    }
}

const mat neutral = { {{1,0},{0,1}} };

const mat m1 = {
    {{2, 2},
    {1, 1}}
}, m0 = {
    {{2, 0},
    {1, 3}}
}, base1 = {
    {{0, 1},
    {0, 0}}
}, base0 = {
    {{0, 0},
    {0, 1}}
};

vector<int> upd1[maxn], upd0[maxn];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        upd1[a].push_back(i);
        upd0[b].push_back(i);
    }

    int B = 1;
    while(B < n) B <<= 1;
    vector<mat> seg(B*2, neutral);

    seg[B] = base0;
    for(int i = 1; i < n; i++){
        seg[i+B] = m0;
    }
    for(int i = B-1; i > 0; i--){
        mul(seg[i<<1|1], seg[i<<1], seg[i]);
    }

    auto update = [&] (int i, const mat& t){
        seg[i+=B] = t;
        for(i >>= 1; i > 0; i >>= 1){
            mul(seg[i<<1|1], seg[i<<1], seg[i]);
        }
    };

    long long res = 0;

    for(int i = 0; i < maxn; i++){
        for(auto u : upd1[i]){
            update(u, (u == 0 ? base1 : m1));
        }
        res = res + seg[1][0][1];
        for(auto u : upd0[i]){
            update(u, (u == 0 ? base0 : m0));
        }
    }

    res %= mod;

    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
