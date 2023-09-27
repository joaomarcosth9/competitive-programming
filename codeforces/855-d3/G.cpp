#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll mod = (ll)1e9 + 7, maxn = 2e5 + 5;

map<ll,ll> m;
ll mapa(ll u){
    if(m.count(u)) return m[u];
    return m[u] = ll(rng()) % mod;
}

vector<int> adj[maxn];
ll h[maxn];
bool sym[maxn];

void dfs(int u = 0, int P = -1){
    h[u] = 0;
    ll val = 0;

    map<ll,int> f;
    map<ll,int> fv;
    for(int v : adj[u]) if(v != P) {
        dfs(v, u);
        val += h[v];
        f[h[v]]++;
        fv[h[v]] = v;
    }

    int c = 0;
    sym[u] = 1;

    for(auto [k, v] : f){
        if(v & 1){
            if(c) {
                sym[u] = 0;
            } else {
                sym[u] = sym[fv[k]];
                c++;
            }
        }
    }

    h[u] = mapa(val);
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs();

    cout << (sym[0] ? "YES" : "NO") << '\n';

    for(int i = 0; i < n; i++){
        adj[i].clear();
        h[i] = sym[i] = 0;
    }
    m.clear();
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if(TC){ cin >> TC;
        while(TC--) solve();
    } else solve();
    return 0;
}

