#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    string s; cin >> s;
    vector<pair<int,int>> v(10);
    for(int i = 0; i <= 9; i++){
        v[i] = {0, i};

    }
    for(auto c : s){
        int nu = c-'0';
        v[nu].first++;
    }
    sort(v.begin(), v.end());
    /* for(auto [k,n] : v){ */
    /*     cout << k << ' ' << n << endl; */
    /* } */
    if(v[0].first < v[1].first){
        if(v[0].second == 0){
            v[0].first++;
            cout << 1;
            while(v[0].first--) cout << v[0].second;
        } else {
            v[0].first++;
            while(v[0].first--) cout << v[0].second;
        }
    } else {
        if(v[0].second == 0){
            v[1].first++;
            while(v[1].first--) cout << v[1].second;
        } else {
            v[0].first++;
            while(v[0].first--) cout << v[0].second;
        }
    }
    cout << endl;
}

int main(){ _
    solve();
    return 0;
}
