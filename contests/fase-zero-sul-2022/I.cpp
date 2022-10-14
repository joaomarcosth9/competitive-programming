#include <bits/stdc++.h>
using namespace std;

const long long LINF = 4.5e18;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define endl '\n'

pair<ll,ll> atek(ll k){
    ll restemp = 1, i = 0;
    for(;; i++){
        ll neww = (9*(ll)pow(10,i))*(i+1);
        if(restemp + neww < k){
            restemp += neww;
        } else break;
    }
    ll algarismo = ((k-restemp) % (i+1));
    return {(k - restemp)/(i+1) + (ll)(pow(10,i)), algarismo};
}

const ll MAX = 2e5+500;
vector<char> res;

ll stringtoll(string a){
    ll p = 1;
    ll rt = a[(ll)a.size()-1]-'0';
    for(ll i = 0, j = a.size()-2; i < p && j >= 0; i++, j--){
        p *= 10;
        rt += (a[j]-'0')*p;
    }
    return rt;
}

void solve(){
    ll k, l, r; cin >> k >> l >> r;
    auto [sl,algl] = atek(l);
    auto [sr,algr] = atek(r);
    string ssl = to_string(sl);
    string ssr = to_string(sr);
    /* cout << sl << ' ' << sr << endl; */
    /* cout << algl << ' ' << algr << endl; */
    for(int i = algl; i < (int)ssl.size(); i++){
        res.pb(ssl[i]);
    }
    for(ll i = sl+1; i < sr; i++){
        string temp = to_string(i);
        for(int j = 0; j < (int)temp.size(); j++){
            res.pb(temp[j]);
        }
    }
    for(int i = 0; i < algr; i++){
        res.pb(ssr[i]);
    }
    string temp;
    for(int i = 0; i < k; i++){
        temp.pb(res[i]);
    }
    ll ress = stringtoll(temp);
    ll maxx = ress;
    ll k10 = (ll)pow(10,k-1);
    for(int i = 1; i+k-1 < (int)res.size(); i++){
        ll tp = ress - (k10 * (res[i-1]-'0'));
        tp *= 10;
        tp += res[i+k-1]-'0';
        maxx = max(maxx, tp);
        ress = tp;
    }
    cout << maxx << endl;
}

signed main(){
    solve();
    return 0;
}
