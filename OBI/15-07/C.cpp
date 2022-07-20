#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5+100;

int n, arr[MAX];
map<int,vector<int>> id;

void solve(){
    vector<int> clean;
    set<int> nu;

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    clean.push_back(0);
    for(int i = 1; i <= n; i++){
        if(arr[i] != clean.back()){
            clean.push_back(arr[i]);
        }
    }
    clean.push_back(0);

    int len = clean.size();

    for(int i = 1; i < len-1; i++){
        nu.insert(clean[i]);
        id[clean[i]].push_back(i);
    }

    int res = 2;
    for(auto el : nu){
        int resel = 2;
        for(auto ii : id[el]){
            if(clean[ii+1] > clean[ii] && clean[ii-1] > clean[ii]){
                resel++;
            }
        }
        res = max(res,resel);
    }
    cout << res << endl;
}

int main(){ _
    solve();
    return 0;
}
