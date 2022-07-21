#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;
const int MAX = 2e2;
typedef long long ll;

ll n, arr[MAX], Adj[MAX], root, res[MAX];
map<ll,int> vis;

void dfs(ll node, int p, int rt){
    vis[node]++;
    res[rt] = p;
    if(!vis[Adj[node]]) dfs(Adj[node], p+1, rt);
    if(p+res[Adj[node]] == n)
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        if(arr[i] == (arr[j]/3) || arr[i] == (arr[j]*2)) Adj[j] = i;
    }
    for(int i = 0; i < n; i++) dfs(i, 1, i);
    cout << arr[root] << endl;
}

int main(){ _
    solve();
    return 0;
}
