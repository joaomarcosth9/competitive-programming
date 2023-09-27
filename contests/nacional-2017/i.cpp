#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> i3;
typedef pair<int, int> ii;
const int maxn = 1e5 + 5;

int p[maxn], sz[maxn];
int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] > sz[v]) swap(u, v);
        sz[v] += sz[u];
        sz[u] = 0;
        p[u] = v;
        return true;
    }
    return false;
}

int par[maxn][18], maxx[maxn][18], val[maxn], tin[maxn], tout[maxn], n, m, q, t = 0;
map<int, int> weight[maxn], is[maxn];
vector<ii> adj[maxn];

bool isAncestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

void predfs(int u = 0, int p = 0) {
    tin[u] = t++;
    par[u][0] = p;
    maxx[u][0] = val[u];
    for (int i = 0; i < 17; i++) {
        par[u][i + 1] = par[par[u][i]][i];
        maxx[u][i + 1] = max(maxx[u][i], maxx[par[u][i]][i]);
    }
    for (auto &[v, w] : adj[u])
        if (v != p) {
            val[v] = w;
            predfs(v, u);
        }
    tout[u] = t++;
}

int query(int u, int v) {
    int U = u;
    int res = INT_MIN;
    if (!isAncestor(u, v)) {
        for (int i = 17; i >= 0; i--) {
            if (!isAncestor(par[u][i], v)) {
                res = max(res, maxx[u][i]);
                u = par[u][i];
            }
        }
        res = max(res, maxx[u][0]);
    }
    u = U;
    if (!isAncestor(v, u)) {
        for (int i = 17; i >= 0; i--) {
            if (!isAncestor(par[v][i], u)) {
                res = max(res, maxx[v][i]);
                v = par[v][i];
            }
        }
        res = max(res, maxx[v][0]);
    }
    return res;
}

void solve() {
    cin >> n >> m;
    iota(p, p + n, 0);
    fill(sz, sz + n, 1);
    vector<i3> all_edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        u--, v--;
        weight[u][v] = w;
        all_edges.emplace_back(w, u, v);
    }

    sort(begin(all_edges), end(all_edges), [&](i3 &a, i3 &b) { return get<0>(a) < get<0>(b); });

    int total = 0;

    for (auto &[w, u, v] : all_edges) {
        if (unite(u, v)) {
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
            is[u][v] = 1;
            total += w;
        }
    }

    predfs();

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        u--, v--;
        if (is[u].count(v)) {
            cout << total << '\n';
            continue;
        }
        int mx = query(u, v);
        cout << total - mx + weight[u][v] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
