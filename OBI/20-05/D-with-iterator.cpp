#include <bits/stdc++.h>

using namespace std;

set<int> A;
set<int> H;
set<int> Result;

void solve(){
    int n, c; cin >> n >> c;
    for (int i = 0; i < c; i++){
        int p, nu; cin >> p >> nu;
        H.insert(p);
        for (int j = 0; j < nu; j++){
            int inf; cin >> inf;
            A.insert(inf);
        }
        set_difference(H.begin(), H.end(), A.begin(), A.end(), inserter(Result, Result.end()));
    } 
    for (set<int>::iterator l = Result.begin(); l != Result.end(); l++){
        cout << *l << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
