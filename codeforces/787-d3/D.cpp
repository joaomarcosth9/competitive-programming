#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5+40;
int n, q, ramos, arr[MAX], vis[MAX];
vector<int> Adj[MAX];
vector<int> Res[MAX];

void dfs(int n){
    vis[n]++;
    Res[ramos].push_back(n);
    for(int i = 0; i < Adj[n].size(); i++){
        if(!vis[Adj[n][i]]){ dfs(Adj[n][i]); }
        ramos++;
    }
}

void solve(){
    ramos = 0;
    for(int i = 0; i < n; i++){
        vis[i] = 0; Adj[i].clear(); Res[i].clear();
    }
    cin >> n; for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        if(a == i) {q = a;}
        Adj[a].push_back(i);
    }
    //for(int i = 1; i <= n; i++){
    //    cout << i << ": ";
    //    for(int j = 0; j < Adj[i].size(); j++){
    //        cout << Adj[i][j] << ' ';
    //    }
    //    cout << endl;
    //}
    dfs(n);
    cout << "Ramos: " << ramos + 1 << endl;
    for(int i = 0; i <= ramos; i++){
        for(int j = 0; j < Res[i].size(); j++){
            cout << Res[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){ _
    int tscf; cin >> tscf;
    int o = tscf;
    while(tscf--) {
        cout << "Testcase: " << o-tscf << endl;
        solve();
    }
    return 0;
}
