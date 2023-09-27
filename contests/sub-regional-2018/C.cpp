#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

const int MAX = 1e5+10;
pair<ll,ll> hh[MAX];
pair<ll,ll> vv[MAX];

struct fenwick {
    int n;
    vector<ll> bit;
    fenwick(int inp){
        n = inp;
        bit.assign(n+1, 0);
    }
    ll rsq(int i){
        ll sum = 0;
        for(; i > 0; i -= (i & (-i))){
            sum += bit[i];
        }
        return sum;
    }
    ll rsq(int l, int r){
        return rsq(r)-rsq(l-1);
    }
    void update(int i, int v){
        for(; i > 0 && i <= n; i += (i & (-i))){
            bit[i] += v;
        }
    }
};

void solve(){
    ll x,y; cin >> x >> y;
    ll h,v; cin >> h >> v;
    fenwick fth(h);
    fenwick ftv(v);
    ll res = h * v;
    for(int i = 0; i < h; i++){
        ll l,r; cin >> l >> r;
        hh[i] = {r,l};
    }
    for(int i = 0; i < v; i++){
        ll b,t; cin >> b >> t;
        vv[i] = {t,b};
    }
    sort(hh, hh+h);
    for(int i = 0; i < h; i++){
        hh[i].first = hh[i].second;
        hh[i].second = i + 1;
    }
    sort(hh, hh+h);
    ll inth = 0;
    for(int i = 0; i < h; i++){
        inth += i + 1 - fth.rsq(hh[i].second);
        fth.update(hh[i].second, 1);
    }
    sort(vv, vv+v);
    for(int i = 0; i < v; i++){
        vv[i].first = vv[i].second;
        vv[i].second = i + 1;
    }
    sort(vv, vv+v);
    ll intv = 0;
    for(int i = 0; i < v; i++){
        intv += i + 1 - ftv.rsq(vv[i].second);
        ftv.update(vv[i].second, 1);
    }
    cout << res + inth + intv + 1 << endl;
}

int main(){
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    solve();
}
