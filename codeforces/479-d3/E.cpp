#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e5+10;
int n, m;
vector<int> Adj[MAX];
vector<int> vis(MAX);
vector<int> scs(MAX);
int res;

void dfs(int nd, int sc, int level){
    vis[nd] = 1;
    int len = Adj[nd].size();
    if(len == 2){
        for(int i = 0; i < len; i++){
            if(Adj[nd][i] == sc && !scs[sc] && level > 2){
                //cout << "Ciclo fechando em " << sc << " -> " << nd << endl;
                scs[sc]++;
                res++; return;
            }
            if(!vis[Adj[nd][i]]){
                dfs(Adj[nd][i], sc, level+1);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){Adj[i].clear();}
    vis.clear();
    scs.clear();
    res = 0;
    for(int i = 0; i < m; i++){
        int n1, n2; cin >> n1 >> n2;
        Adj[n1].push_back(n2);
        Adj[n2].push_back(n1);
    }
    for(int i = 1; i <= n; i++) if(!vis[i]) {dfs(i,i,1);}
    cout << res << endl;

}

int main(){ _
    solve();
    return 0;
}
