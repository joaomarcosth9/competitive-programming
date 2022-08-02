#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    string t; cin >> t;
    vector<int> M(t.size());
    int n; cin >> n;
    vector<pair<int,string>> Ss(n);
    map<int,set<int>> Df;
    cout << t << endl;
    for(int i = 0; i < n; i++){
        string ss; cin >> ss;
        Ss[i] = {ss.size(), ss};
    }
    sort(begin(Ss), end(Ss), greater<pair<int,string>>());
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
                //for(int k = 0; k < (int)s.size(); k++){
                //    Df[j+k].insert(i+1);
                //    M[j+k] = 1;
                //}
                Df[j].insert(i+1);
                M[j] = 1;
            }
        }
    }
    for(auto [len,st] : Ss){
        cout << len << ": " << st << endl;
    }
    for(auto [k,v] : Df){
        cout << k << ": ";
        for(auto a : v) cout << a << ' ';
        cout << endl;
    }
    for(int i = 0; i < (int)M.size(); i++){
        cout << M[i] << ' ';
    }
    cout << endl;
}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
