#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    if(k * 2 < n){
        cout << "NO\n";
        return;
    } else {
        map<int,int> u;
        for(int i = 0; i < n; i++){
            u[v[i]]++;
            if(u[v[i]] > 2){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main(){
    int testcases; cin >> testcases;
    for(int i = 1; i <= testcases; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
