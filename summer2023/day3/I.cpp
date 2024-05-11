#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<ll, ll> ii;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

const ll maxn = 1e5 + 5;
ll prof[maxn];
ll dp[maxn];
bool vis[maxn];
vector<ll> adj[maxn];
map<ii, ll> how_many;
map<ii, bool> is_bridge;

void dfs(ll u, ll l = -1, ll p = 0) {
    prof[u] = p;
    vis[u] = true;
    for (ll v : adj[u])
        if (v != l) {
            if (vis[v]) {
                if (prof[v] < prof[u]) dp[v]--, dp[u]++;
            } else {
                dfs(v, u, p + 1);
                dp[u] += dp[v];
            }
        }
}

void dfs2(ll u, ll l = -1) {
    vis[u] = true;
    db(u, l, dp[u]);
    db(adj[u]);
    if (l != -1 && dp[u] == 0) {
        ll _l = l, _u = u;
        if (_l > _u) swap(_l, _u);
        if (how_many[ii(_l, _u)] == 1) {
            db(l, u);
            is_bridge[ii(_l, _u)] = true;
        }
    }
    for (ll v : adj[u])
        if (!vis[v]) {
            db(v, vis[v]);
            dfs2(v, u);
        }
}

struct edge {
    ll u, v, id;
    edge(ll _u, ll _v, ll _id) : u(_u), v(_v), id(_id) {}
};

struct dsu {
    vector<ll> id, sz;

    dsu(ll n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

    ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

    void unite(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    map<ll, vector<edge>> edges;
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        u--, v--;
        edges[w].emplace_back(edge(u, v, i));
    }
    dsu cc(n);
    vector<ll> res(m, 0);
    for (auto &[w, edg] : edges) {
        db(w);
        for (auto &[u, v, i] : edg) {
            u = cc.find(u), v = cc.find(v);
            if (u > v) swap(u, v);
            if (u == v) continue;
            res[i] = 1;
            if (how_many[ii(u, v)] < 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            how_many[ii(u, v)]++;
        }
        for (auto [u, v, _i] : edg) {
            for (auto i : {u, v}) {
                dp[i] = prof[i] = vis[i] = 0;
            }
        }
        for (auto [u, v, i] : edg) {
            if (!vis[u]) dfs(u);
        }
        for (auto [u, v, _i] : edg) {
            vis[u] = vis[v] = 0;
        }
        for (auto [u, v, i] : edg) {
            if (!vis[u]) dfs2(u);
        }
        for (auto [u, v, i] : edg) {
            if (u == v) continue;
            if (is_bridge[ii(u, v)]) {
                res[i] = 2;
            }
        }
        for (auto [u, v, i] : edg) {
            adj[u].clear();
            adj[v].clear();
            if (u == v) continue;
            cc.unite(u, v);
        }
    }
    for (ll i = 0; i < m; i++) {
        if (res[i] == 0) {
            cout << "none" << endl;
        } else if (res[i] == 1) {
            cout << "at least one" << endl;
        } else if (res[i] == 2) {
            cout << "any" << endl;
        }
    }
}

signed main() {
    solve();
    return 0;
}
