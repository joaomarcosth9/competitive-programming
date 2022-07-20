#include <bits/stdc++.h>

using namespace std;

void int_to_list(int n, vector<int>& V){
    while(n / 10){
        V.push_back(n % 10);
        n = n/10;
    }
    V.push_back(n);
    reverse(V.begin(), V.end());
}

void solve(){ 
    vector<int> V;
    int n; cin >> n;
    if (n % 2 == 0){
        cout << 0 << endl;
        return;
    }
    int_to_list(n, V);
    if (V[0] % 2 == 0){
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i < V.size(); i++){
        if (V[i] % 2 == 0){
            cout << 2 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        solve();
    }
    return 0;
}
