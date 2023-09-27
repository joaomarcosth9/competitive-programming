#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll; typedef pair<int,int> ii;
int testcases = 0;
const int INF = 1.05e9; const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

typedef tuple<int,int,int> i3;
const int maxn = 2.1e5;
vector<int> adj[maxn];

namespace seg {
    const int MAX = maxn;
    const ll NEUTRAL = INT_MIN; // merge(a, neutral) = a
    ll merge(ll a, ll b) { return max(a, b); }
    int sz; // size of the array
    ll tree[4*MAX], lazy[4*MAX];
    int le(int n) { return 2*n+1; }
    int ri(int n) { return 2*n+2; }
    void push(int n, int esq, int dir) {
        if (lazy[n] == 0) return;
        tree[n] += lazy[n] * (dir - esq + 1);
        if (esq != dir) {
            lazy[le(n)] += lazy[n];
            lazy[ri(n)] += lazy[n];
        }
        lazy[n] = 0;
    }
    void build(const vector<ll> &v, int n, int esq, int dir) {
        if (esq == dir) tree[n] = v[esq];
        else {
            int mid = (esq + dir) / 2;
            build(v, le(n), esq, mid);
            build(v, ri(n), mid+1, dir);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
    void build(const vector<ll> &v) { sz = v.size(); build(v, 0, 0, sz-1); }
    ll query(int l, int r, int n=0, int esq=0, int dir=sz-1) {
        push(n, esq, dir);
        if (esq > r || dir < l) return NEUTRAL;
        if (l <= esq && dir <= r) return tree[n];
        int mid = (esq + dir)/2;
        return merge(query(l, r, le(n), esq, mid), query(l, r, ri(n), mid+1, dir));
    }
    void update(int l, int r, ll v, int n=0, int esq=0, int dir=sz-1) {
        push(n, esq, dir);
        if (esq > r || dir < l) return;
        if (l <= esq && dir <= r) {
            lazy[n] += v;
            push(n, esq, dir);
        } else {
            int mid = (esq + dir)/2;
            update(l, r, v, le(n), esq, mid);
            update(l, r, v, ri(n), mid+1, dir);
            tree[n] = merge(tree[le(n)], tree[ri(n)]);
        }
    }
}

namespace hld {
    const int MAX = maxn;
    int t, sz[MAX], pos[MAX], pai[MAX], head[MAX];
    bool e = 0;
    ll merge(ll a, ll b) { return max(a, b); } // how to merge paths
    void dfs_sz(int u, int p=-1) {
        sz[u] = 1;
        for (int &v : adj[u]) if (v != p) {
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]] || adj[u][0] == p) swap(v, adj[u][0]);
        }
    }
    void dfs_hld(int u, int p=-1) {
        pos[u] = t++;
        for (int v : adj[u]) if (v != p) {
            pai[v] = u;
            head[v] = (v == adj[u][0] ? head[u] : v);
            dfs_hld(v, u);
        }
    }
    void build(int root) {
        dfs_sz(root);
        t = 0;
        pai[root] = root;
        head[root] = root;
        dfs_hld(root);
    }
    void build(int root, vector<ll>& v) {
        build(root);
        vector<ll> aux(v.size());
        for (int i = 0; i < (int)v.size(); i++) aux[pos[i]] = v[i];
        seg::build(aux);
    }
    void build(int root, vector<i3>& edges) { // use this if weighted edges
        build(root);
        e = 1;
        vector<ll> aux(edges.size()+1);
        for (auto [u, v, w]: edges) {
            if (pos[u] > pos[v]) swap(u, v);
            aux[pos[v]] = w;
        } 
        seg::build(aux);
    }
    ll query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) return seg::query(pos[u]+e, pos[v]);
        else {
            ll qv = seg::query(pos[head[v]], pos[v]);
            ll qu = query(u, pai[head[v]]);
            return merge(qu, qv);
        }
    }
    void update(int u, int v, ll k) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) seg::update(pos[u]+e, pos[v], k);
        else {
            seg::update(pos[head[v]], pos[v], k);
            update(u, pai[head[v]], k);
        }
    }
    int lca(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        return (head[u] == head[v] ? u : lca(u, pai[head[v]]));
    }
    ll query_subtree(int u) {
        return seg::query(pos[u], pos[u]+sz[u]-1);
    }
}

vector<int> id, sz;
void dsu_build(int n) {
    id.resize(n);
    sz.assign(n, 1);
    iota(id.begin(), id.end(), 0);
}

int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

void unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], id[b] = a;
}

vector<i3> edg; // {peso,[x,y]}

pair<ll, vector<i3>> kruskal(int n) {
	dsu_build(n);
	sort(edg.begin(), edg.end());
	ll cost = 0;
	vector<i3> mst;
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		mst.emplace_back(x, y, w);
		cost += w;
		unite(x,y);
	}
	return {cost, mst};
}

void solve(){
    int n, m, q; cin >> n >> m >> q;
    map<ii,int> cost;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        if(u > v) swap(u, v);
        if(u == v) continue;
        int& at = cost[ii(u,v)];
        if(at == 0 || w < at){
            at = w;
            edg.emplace_back(w, u, v);
        }
    }
    auto [_, mst] = kruskal(n);
    for(auto [u,v,__] : mst){
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    hld::build(0, mst);
    while(q--){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;
        int qq = hld::query(u, v);
        cout << (qq > w && u != v ? "Yes" : "No") << endl;
    }
}

signed main(){
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);cin.tie(0);
#endif
    int tsts = 1;
    if(testcases) cin >> tsts;
    while(tsts--) solve();
    return 0;
}
