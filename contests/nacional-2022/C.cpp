#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

void solve(){
    ll n, p, h; cin >> n >> p >> h;
    ll hh = h;
    vector<ll> v;
    for(ll i = 1, sz = (1ll << n); i <= n; i++, sz >>= 1){
        v.push_back(hh);
        if(hh > (sz >> 1)) hh = sz-hh+1;
    }
    reverse(begin(v), end(v));
    ll i = p, it = 0;
    hh = 1;
    string res = "";
    for(ll sz = (1ll << n); sz > 1; sz >>= 1){
        string add = "LR";
        if(i > (sz >> 1)){
            add = "RL";
            i -= (sz >> 1);
        }
        if(hh != v[it]){
            i = (sz >> 1)-i+1;
            res += add[0];
        } else {
            res += add[1];
        }
        hh = v[it++];
    }
    assert(res != "");
    cout << res << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
