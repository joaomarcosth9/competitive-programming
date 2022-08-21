#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    string t; cin >> t;
    vector<int> M(t.size());
    int n; cin >> n;
    vector<pair<int,string>> Ss(n);
    map<int,set<pair<int,int>>> Df;
    cout << t << endl;
    for(int i = 0; i < n; i++){
        string ss; cin >> ss;
        Ss[i] = {ss.size(), ss};
    }
    //sort(begin(Ss), end(Ss), greater<pair<int,string>>());
    for(int i = 0; i < n; i++){
        auto [sz,s] = Ss[i];
        for(int j = 0; j < (int)t.size(); j++){
            int dr = 0;
            for(int k = 0; k < (int)s.size(); k++){
                if(t[j+k] != s[k]){
                    dr++;
                    break;
                }
            }
            if(!dr){
                for(int k = 0; k < (int)s.size() && k+j < (int)t.size(); k++){
                    M[j+k] = 1;
                }
                Df[i+1].insert({j+1,j+sz});
            }
        }
    }
    for(int i = 0; i < (int)M.size(); i++){
        if(!M[i]){
            cout << -1 << endl;
            return;
        }
    }
    //for(auto [len,st] : Ss){
    //    cout << len << ": " << st << endl;
    //}
    for(auto [k,v] : Df){
        cout << k << ": ";
        for(auto [st,en] : v) cout << st << ',' << en << ' ';
        cout << endl;
    }
    vector<int> P(t.size());
    int sstr = -1;
    int slen = INT_MIN;
    int estr = -1;
    int elen = INT_MIN;
    for(auto [ss,rr] : Df){
        for(auto [st,en] : rr){
            if(st == 1 && en-st+1 > slen){
                sstr = ss;
                slen = en-st+1;
            }
            if(en == (int)t.size() && en-st+1 > elen){
                estr = ss;
                elen = en-st+1;
            }
        }
    }
    cout << sstr << ' ' << estr << endl;
    for(int i = 0; i < slen; i++){
        P[i] = 1;
    }
    for(int j = (int)t.size()-1; j >= (int)t.size()-elen; j--){
        P[j] = 1;
    }
    for(int i = 0; i < (int)t.size(); i++){
        cout << P[i] << ' ';
    }
    cout << endl;
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
