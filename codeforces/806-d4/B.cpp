#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    int n; cin >> n;
    map<char,int> M;
    string s; cin >> s;
    int res = 0;
    for(int i = 0; i < n; i++){
        if(!M[s[i]]){
            res+=2;
            M[s[i]]++;
        }
        else {
            M[s[i]]++;
            res++;
        }
    } 
    cout << res << endl;
}

int main(){ _
    int testcases; cin >> testcases;
    for (int i = 0; i < testcases; i++){
        solve();
    }
    return 0;
}
