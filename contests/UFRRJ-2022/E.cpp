#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif
typedef long long ll;

const int mod = 1e9+7, p = 2, maxn = 2e5+5;

ll bpow(ll n, ll e){
    ll res = 1, b = n;
    while(e){
        if(e & 1) res = res * b % mod;
        e >>= 1, b = b * b % mod;
    }
    return res;
}

ll P[maxn], invP[maxn];

int n, q;
string s;

ll h[30][maxn];
int idx[30][maxn];

string solve2(int i1, int j1, int i2, int j2){
    for(char l = 'a'; l <= 'z'; l++){
        int id = l - 'a';
        int index = idx[id][i1];
        if(index <= j1 && index != -1){
            index = index - i1;
            if(i2 + index >= n) continue;
            char corresp = s[i2+index-1];
            int idcorresp = corresp - 'a';
            ll _hash1 = (h[id][j1] - h[id][i1-1] + mod) * invP[i1-1] % mod;
            ll _hash2 = (h[idcorresp][j2] - h[idcorresp][i2-1] + mod) * invP[i2-1] % mod;
            if(_hash1 != _hash2){
                return "NO";
            }
        }
    }
    return "YES";
}

void solve(){
    cin >> n >> q >> s;
    for(char l = 'a'; l <= 'z'; l++){
        int id = l - 'a';
        for(int i = 1; i <= n; i++){
            h[id][i] = h[id][i-1];
            if(s[i-1] == l){
                h[id][i] = (h[id][i] + P[i]) % mod;
            }
        }
    }
    for(char l = 'a'; l <= 'z'; l++){
        int id = l - 'a';
        int last = -1;
        for(int i = n; i > 0; i--){
            if(s[i-1] == l) last = i;
            idx[id][i] = last;
        }
    }
    while(q--){
        int x, y, t; cin >> x >> y >> t;
        cout << solve2(x, x+t-1, y, y+t-1) << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    P[0] = invP[0] = 1;
    P[1] = p; invP[1] = bpow(p, mod-2);

    for(int i = 2; i < maxn; i++){
        P[i] = P[i-1] * P[1] % mod;
        invP[i] = invP[i-1] * invP[1] % mod;
    }

    solve();
    return 0;
}
