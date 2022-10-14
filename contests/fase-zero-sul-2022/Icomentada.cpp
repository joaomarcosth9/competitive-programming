#include <iostream>
#include <math.h>
using namespace std;

const long long LINF = 4.5e18;
using ll = long long;
#define pb push_back
#define eb emplace_back
#define endl '\n'

pair<ll,int> atek(ll k){
    ll res = 1, i = 0;
    for(;; i++){
        ll neww = (9*(ll)pow(10,i))*(i+1);
        if(res + neww < k){
            res += neww;
        } else break;
    }
    int algarismo = ((k-res) % (i+1));
    /* ll f10 = (ll)pow(10,i); */
    /* cout << "Fst pot 10 < k: " << f10 << endl; */
    /* cout << "n de chars ate fst pot 10: " << res << endl; */
    /* cout << "n de algarismos: " << i+1 << endl; */
    /* cout << "numero " << (k - res)/(i+1) + (pow(10,i)) << endl; */
    /* cout << "Algarismo " << algarismo << endl; */
    return {(k - res)/(i+1) + (pow(10,i)), algarismo};
}

const int MAX = 2e5+500;

char res[MAX];

void solve(){
    ll k, l, r; cin >> k >> l >> r;
    /* cout << atek(l).first << endl << atek(r).first << endl; */
    /* string sl, sr; */
    /* int algl, algr; */
    auto [sl,algl] = atek(l);
    auto [sr,algr] = atek(r);
    /* cout << sl << ' ' << sr << endl; */
    /* cout << algl << ' ' << algr << endl; */
    string ssl = to_string(sl);
    string ssr = to_string(sr);
    int ii = 0;
    for(int i = algl; i < (int)ssl.size(); i++, ii++){
        res[ii] = ssl[i];
    }
    for(int i = sl+1; i < sr; i++){
        string temp = to_string(i);
        for(int j = 0; j < (int)temp.size(); j++, ii++){
            res[ii] = temp[j];
        }
    }
    for(int i = 0; i <= algr; i++, ii++){
        res[ii] = ssr[i];
    }
    string temp;
    for(int i = 0; i < k; i++){
        temp.pb(res[i]);
    }
    for(int i = 0; i < ii; i++){
        cout << res[i];
    }
    cout << endl;
    /* cout << res << endl; */
    ll ress = stoll(temp);
    ll maxx = ress;
    ll k10 = (ll)pow(10,k-1);
    /* cout << "K10 " << k10 << endl; */
    /* cout << "ress " << ress << endl; */
    for(int i = 1; i+k-1 < ii; i++){
        /* cout << "Digito pra tirar " << res[i-1]-'0' << endl; */
        ll tp = ress - (k10 * (res[i-1]-'0'));
        /* cout << ress << ' ' << tp << endl; */
        tp *= 10;
        /* cout << ress << ' ' << tp << endl; */
        tp += res[i+k-1]-'0';
        /* cout << ress << ' ' << tp << endl; */
        maxx = max(maxx, tp);
        ress = tp;
    }
    cout << maxx << endl;
}

int main(){
    solve();
    return 0;
}
