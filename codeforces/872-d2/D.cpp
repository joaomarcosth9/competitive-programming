#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(x...)
#endif
#define int long long

const int maxn = 2e5+5, mod = 1e9 + 7;
long long fat[maxn], invfat[maxn];

long long binpow(long long b, long long e){
    long long res = 1;
    while(e){
        if(e & 1) res = res * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return res;
}

long long invmod(long long u){
    return binpow(u, mod-2);
}

long long nchoosek(long long n, long long k){
    return ((fat[n] * invfat[k] % mod) + mod) * invfat[n-k] % mod;
}

vector<int> adj[maxn];
long long dp[maxn], sz[maxn];
int n, k;

void dfs(int u, int p = -1, int d = 0){
    dp[u] = d;
    sz[u] = 1;
    for(int v : adj[u]) if(v != p) {
        dfs(v, u, d+1);
        dp[u] += dp[v];
        sz[u] += sz[v];
    }
}
 
void dfs_dp(int u, int p = -1){
    if(u != 0){
        dp[u] = (dp[p] - sz[u] + 1ll) + (n - sz[u] - 1ll);
    }
    for(int v : adj[u]) if(v != p) {
        dfs_dp(v, u);
    }
}
 
void solve(){
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    if(k & 1){
        cout << 1 << '\n';
        return;
    }
    dfs(0);
    dfs_dp(0);
    long long res = 0;
    debug(vec(dp, n));
    for(int i = 0; i < n; i++){
        res = (res + dp[i] + n-1) % mod;
    }
    res = res * invmod(2) % mod;
    cout << (res * invmod(nchoosek(n, k))) % mod << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    fat[0] = 1;
    for(int i = 1; i < maxn; i++){
        fat[i] = fat[i-1] * i % mod;
    }
    invfat[0] = 1;
    for(int i = 1; i < maxn; i++){
        invfat[i] = invfat[i-1] * invmod(i) % mod;
    }
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}
