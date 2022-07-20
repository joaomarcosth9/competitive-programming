#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int MAX = 205;

vector<int> Adj[MAX];
int alt[MAX];
int vis[MAX];
int alc[MAX];
int res;

void dfs(int v){
    vis[v]++;
    res++;
    for(int i = 0; i < Adj[v].size(); i++){  
        if(!vis[Adj[v][i]]) dfs(Adj[v][i]);
    }
}

void solve(){
    int s, t, p; cin >> s >> t >> p;
    for(int i = 1; i <= s; i++){
        cin >> alt[i];
    }
    for(int i = 0; i < t; i++){
        int t1, t2; cin >> t1 >> t2;
        if(alt[t1] > alt[t2]) {
            Adj[t1].push_back(t2);
        } else if (alt[t2] > alt[t1]) {
            Adj[t2].push_back(t1);
        }
    }
    dfs(p);
    cout << res-1 << endl;
}

int main(){ _
    solve();
    return 0;
}
