#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 2.1e5;
long long mod[3] = {999998789, 1000000007, 1000008259};
const long long p = 109283;
/* const long long p = 41; */
int n, root = 1;
vector<int> adj[maxn];
long long arr[maxn], dp[3][maxn], dp2[3][maxn];
long long h[3];
long long B[3][maxn];

void dfs(int u, int _p = -1){
    long long dpv[3] = {0,0,0};
    for(int v : adj[u]) if(v != _p) {
        dfs(v, u);
        for(int i = 0; i < 3; i++)
            dpv[i] = (dpv[i] + dp[i][v]) % mod[i];
    }
    for(int i = 0; i < 3; i++)
        dp[i][u] = ((dpv[i]) * p + 1) % mod[i];
}

void dfs2(int u, int _p = -1){
    if(u == root){
        for(int i = 0; i < 3; i++)
            dp2[i][u] = dp[i][u];
    } else {
        for(int i = 0; i < 3; i++)
            dp2[i][u] = (dp[i][u] + ((dp2[i][_p] - dp[i][u] * p % mod[i]) * p % mod[i]) + mod[i]) % mod[i];
    }
    for(int v : adj[u]) if(v != _p) {
        dfs2(v, u);
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n-1; i++) cin >> arr[i];
    for(int i = 0; i < 3; i++){
        B[i][0] = 1;
        for(int j = 1; j <= n; j++){
            B[i][j] = (B[i][j-1] * p) % mod[i];
            db(B[i][j]);
        }
    }
    map<int,int> freq;
    for(int i = 0; i < n-1; i++) freq[arr[i]]++;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int j = 0; j < 3; j++){
        for(int i = 0; i <= n; i++){
            h[j] = (h[j] + B[j][i] * freq[i]) % mod[j];
        }
    }
    dfs(root);
    dfs2(root);
    map<int,bool> has;
    for(int i = 0; i < 3; i++) has[h[i]] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            has[(h[j] + B[j][i]) % mod[j]] = 1;
        }
    }
    vector<int> res;
    for(int i = 1; i <= n; i++){
        int is = 1;
        for(int j = 0; j < 3; j++){
            is &= has[dp2[j][i]];
        }
        if(is) res.push_back(i);
    }
    cout << res.size() << endl;
    for(int v : res) cout << v << " ";
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
