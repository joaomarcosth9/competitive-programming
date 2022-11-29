#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e3+500;
typedef long long ll;

int n, l;
vector<int> adj[MAX];
int dp[MAX];
const int MOD = 1e9+7;
int res = 0;

int dfs(int u){
    if(dp[u]) return dp[u];
    int temp = 0;
    if(adj[u].empty()){
        res++;
        return dp[u] = 1;
    } else for(int v : adj[u]){
        temp += dfs(v);
        temp %= MOD;
    }
    return dp[u] = temp;
}

void solve(){
    cin >> n >> l;
    for(int i = 0; i < l; i++){
        int a; cin >> a;
        while(a--){
            int nn; cin >> nn; nn--;
            adj[i].push_back(nn);
        }
    }
    dfs(0);
    cout << dp[0] << ' ' << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}
