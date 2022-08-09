#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 1e5;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> Adj(MAX);
    vector<pair<int,int>> A;
    vector<int> U(MAX);
    for(int i = 0; i < n; i++) cin >> U[i];
    for(int i = 0; i < m; i++){
        int a1,a2; cin >> a1 >> a2;
        A.push_back({min(a1,a2),max(a1,a2)});
        Adj[a1].push_back(a2);
        Adj[a2].push_back(a1);
    }
    if(m%2==0){
        cout << 0 << endl;
        return;
    }
    
    for(int i = 0; i < m; i++){
        auto [a1,a2] = A[i];
        if(Adj[a1].size()%2 == 0 && Adj[a2].size()%2 == 0){
            // even
        }
    }

}

int main(){ _
    int tscf; cin >> tscf;
    while(tscf--) solve();
    return 0;
}
