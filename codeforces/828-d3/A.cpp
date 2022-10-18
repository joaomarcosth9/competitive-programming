#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    map<int,char> mp;
    string s; cin >> s;
    int db = 1;
    for(int i = 0; i < n; i++){
        if(mp[v[i]]){
            db &= (mp[v[i]] == s[i]);
            continue;
        }
        mp[v[i]] = s[i];
    }
    cout << (db ? "YES" : "NO") << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
