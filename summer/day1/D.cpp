#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll; typedef pair<int,int> ii;
int testcases = 0;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif
const ll p = 31, mod = 1e9+7;

ll binpow(ll b, ll e){
    int r = 1;
    while(e){
        if(e & 1){
            r = (r * b) % mod;
        }
        e >>= 1;
        b = (b * b) % mod;
    }
    return r;
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int> divs {1};
    for(int i = 2; i+i <= n; i++){
        if(n % i) continue;
        divs.push_back(i);
    }
    sort(divs.begin(), divs.end());
    vector<ll> h(2*n+1);
    s += s;
    ll bp = p;
    for(int i = 0; i < 2 * n; i++){
        int c = s[i] - 'a' + 1;
        h[i+1] = (h[i] + (c * bp)) % mod;
        bp = (bp * p) % mod;
    }
    auto query = [&] (int l, int r){
        l++, r++;
        return ((h[r] - h[l-1] + mod) % mod * 1LL * binpow(binpow(p, l-1), mod-2)) % mod;
    };
    ll res = 1;
    for(int size : divs){
        bool eq = 1;
        ll base = query(0, size-1);
        for(int i = size; i < n; i += size){
            eq &= (query(i, i+size-1) == base);
            if(!eq) break;
        }
        if(eq){
            res += n;
        }
    }
    cout << res << endl;
}

signed main(){
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
