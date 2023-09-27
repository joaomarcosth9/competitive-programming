#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, int, int> i3;
const int maxn = 1e5 + 5;

int lg[maxn];
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

namespace sparse {
    int n, e;
    typedef vector<int> vi;
    vector<vi> st;
    void build(vi &v) {
        n = v.size();
        e = __lg(n);
        st.assign(e + 1, vi(n));
        for (int i = 0; i < n; i++) st[0][i] = v[i];
        for (int i = 1; i <= e; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        if (l > r) return INT_MIN;
        int i = lg[r - l + 1];
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
}; // namespace sparse

int n, m, q;
map<int, int> weight[maxn], is[maxn];
vector<int> adj[maxn];

namespace hld {
    int head[maxn], pos[maxn], par[maxn], sz[maxn];
    int t = 0;
    void dfs_sz(int u = 0, int p = 0) {
        sz[u] = 1;
        par[u] = p;
        for (int &v : adj[u])
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
            }
    }
    void dfs_build(int u = 0, int p = -1) {
        pos[u] = t++;
        for (int v : adj[u])
            if (v != p) {
                if (v == adj[u][0])
                    head[v] = head[u];
                else
                    head[v] = v;
                dfs_build(v, u);
            }
    }
    void build(int root, vector<i3> &edges) {
        head[root] = par[root] = root;
        dfs_sz(root);
        dfs_build(root);
        vector<int> aux(edges.size() + 1);
        for (auto &[u, v, w] : edges) {
            if (par[u] == v) swap(u, v);
            // par[v] == u;
            aux[pos[v]] = w;
        }
        sparse::build(aux);
    }
    int query(int u, int v) {
        if (pos[u] > pos[v]) swap(u, v);
        if (head[u] == head[v]) return sparse::query(pos[u] + 1, pos[v]);
        auto qu = sparse::query(pos[head[v]], pos[v]);
        auto qv = query(u, par[head[v]]);
        return max(qu, qv);
    }
} // namespace hld

void solve() {
    cin >> n >> m;
    iota(p, p + n, 0);
    fill(sz, sz + n, 1);
    vector<i3> all_edges, edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        weight[u][v] = weight[v][u] = w;
        all_edges.emplace_back(w, u, v);
    }

    sort(begin(all_edges), end(all_edges), [&](i3 &a, i3 &b) { return get<0>(a) < get<0>(b); });

    int total = 0;

    for (auto [w, u, v] : all_edges) {
        if (unite(u, v)) {
            edges.emplace_back(u, v, w);
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            is[u][v] = is[v][u] = 1;
            total += w;
        }
    }

    hld::build(0, edges);

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (is[u].count(v)) {
            cout << total << '\n';
            continue;
        }
        auto maxx = hld::query(u, v);
        cout << total - maxx + weight[u][v] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lg[1] = 0;
    for (int i = 2; i < maxn; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    solve();
    return 0;
}
