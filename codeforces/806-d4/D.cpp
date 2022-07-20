#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;

using namespace std;
const int MAX = 1e5;

int number = 97, n;
string strs[MAX];
int res[MAX];

ll strhash(string s){
    int len = s.size();
    ll hash = 0;
    for(int i = 0; i < len; i++){ 
        hash += s[i] * pow(number, i);
    }
    return hash;
}

void solve(){
    memset(res, 0, sizeof(res));
    cin >> n;
    map<ll,int> M;
    for(int i = 0; i < n; i++){
        cin >> strs[i];
        M[strhash(strs[i])]=1;
    }
    for(int i = 0; i < n; i++){
        for(int k = 1; k < strs[i].size(); k++){
            string str1 = strs[i].substr(0,k);
            string str2 = strs[i].substr(k,strs[i].size());
            if(M[strhash(str1)] && M[strhash(str2)]){
                res[i] = 1;
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << res[i];
    }
    cout << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
