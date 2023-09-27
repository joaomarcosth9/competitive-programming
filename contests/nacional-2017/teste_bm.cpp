#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int,int,int> i3;
const int maxn = 1e5+5;

struct DSU {
    vector<int> p, sz;
    DSU(int n){
        p.resize(n);
        sz.assign(n, 1);
        iota(begin(p), end(p), 0);
    }
    int find(int u){
        return u == p[u] ? u : p[u] = find(p[u]);
    }
    bool unite(int u, int v){
        u = find(u);
        v = find(v);
        if(u != v){
            if(sz[u] > sz[v]) swap(u, v);
            sz[v] += sz[u];
            sz[u] = 0;
            p[u] = v;
            return true;
        }
        return false;
    }
};

namespace sparse {
    int m[20][maxn], n;
    void build(int n2, vector<int>& v) {
        n = n2;
        for (int i = 0; i < n; i++) m[0][i] = v[i];
        for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) < n; i++)
            m[j][i] = max(m[j-1][i], m[j-1][i+(1<<(j-1))]);
    }
    int query(int a, int b) {
        if(a > b) return INT_MIN;
        int j = __builtin_clz(1) - __builtin_clz(b-a+1);
        return max(m[j][a], m[j][b-(1<<j)+1]);
    }
}

int n, m;
vector<int> adj[maxn];

namespace hld {
    int head[maxn], pos[maxn], par[maxn], sz[maxn];
    int t = 0;
    void dfs_sz(int u = 0, int p = 0){
        sz[u] = 1;
        par[u] = p;
        for(int& v : adj[u]) if (v != p) {
            dfs_sz(v, u);
            sz[u] += sz[v];
            if(sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
        }
    }
    void dfs_build(int u = 0, int p = -1){
        pos[u] = t++;
        for(int v : adj[u]) if(v != p) {
            if(v == adj[u][0]) head[v] = head[u];
            else head[v] = v;
            dfs_build(v, u);
        }
    }
    void build(int root, vector<i3>& edges){
        head[root] = par[root] = root;
        dfs_sz(root);
        dfs_build(root);
        vector<int> aux(edges.size()+1);
        for(auto& [u, v, w] : edges){
            if(par[u] == v) swap(u, v);
            // par[v] == u;
            aux[pos[v]] = w;
        }
        sparse::build(n, aux);
    }
    int query(int u, int v){
        if(pos[u] > pos[v]) swap(u, v);
        if(head[u] == head[v]) return sparse::query(pos[u] + 1, pos[v]);
        auto qu = sparse::query(pos[head[v]], pos[v]);
        auto qv = query(u, par[head[v]]);
        return max(qu, qv);
    }
}

void solve(){
    cin >> n >> m;
    vector<i3> all_edges, edges;
    map<int, map<int,int>> weight, is;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        weight[u][v] = weight[v][u] = w;
        all_edges.emplace_back(w, u, v);
    }

    DSU dsu(n);
    sort(begin(all_edges), end(all_edges));

    int total = 0;

    for(auto [w, u, v] : all_edges){
        if(dsu.unite(u, v)){
            edges.emplace_back(u, v, w);
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            is[u][v] = is[v][u] = 1;
            total += w;
        }
    }

    hld::build(0, edges);

    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        u--, v--;
        if(is[u][v]) {
            cout << total << '\n';
            continue;
        }
        auto maxx = hld::query(u, v);
        assert(maxx > 0);
        cout << total - maxx + weight[u][v] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

