#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
typedef long long ll;

const int MAX = 5e4+100;
int n;
vector<int> adj[MAX];
int vis[MAX];
map<int,int> res;
map<int,int> used;

void dfs(int so, int no, int l){
    // cout << no << ' ' << l << '\n';
    res[l]++;
    vis[no]++;
    for(int i = 0; i < (int)adj[no].size(); i++){
        if(!vis[adj[no][i]]) dfs(so, adj[no][i], l+1);
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        dfs(i, i, 1);
        for(int j = 0; j < MAX; j++) vis[j] = 0;
    }
    int mx = -1;
    for(auto [a,b] : res){
        mx = max(mx, a);
    }
    cout << mx << endl << res[mx]/2 << endl;
}

int main(){
    // _
    solve();
    return 0;
}
