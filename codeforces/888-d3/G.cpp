#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define endl '\n'
#define cerr                                                                                                           \
    if (false) cerr
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

struct UnionFind {
    vector<int> p, sz;
    UnionFind(int n) {
        p.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i, sz[i] = 1;
        }
    }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    bool same(int u, int v) { return find(u) == find(v); }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[v] > sz[u]) swap(u, v);
        sz[u] += sz[v];
        p[v] = u;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> hh(n);
    vector<pair<int, int>> h(n);
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i].first;
        hh[i] = h[i].first;
        h[i].second = i;
    }

    sort(begin(h), end(h));

    debug(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        debug(u, v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int q;
    cin >> q;
    debug(q);
    vector<vector<tuple<int, int, int, int>>> has(n);

    for (int i = 0; i < q; i++) {
        int u, v, e;
        cin >> u >> v >> e;
        u--, v--;
        has[(n - 1) / 2].emplace_back(u, v, hh[u] + e, i);
    }

    vector<int> l(q, 0), r(q, n - 1), ans(q);

    while (1) {
        UnionFind dsu(n);
        vector<bool> is(n);
        bool br = 1;
        for (int i = 0; i < n; i++) {
            auto &[H, u] = h[i];
            is[u] = 1;
            for (auto &v : adj[u]) {
                if (!is[v]) continue;
                dsu.unite(v, u);
            }
            if (has[i].size()) {
                br = 0;
                for (auto &[U, V, mx, id] : has[i]) {
                    if (dsu.same(U, V) && H <= mx) {
                        ans[id] = 1;
                        continue;
                    }
                    if (dsu.same(U, V)) {
                        r[id] = i - 1;
                    } else {
                        l[id] = i + 1;
                    }
                    if (l[id] > r[id]) continue;
                    int new_mid = l[id] + (r[id] - l[id]) / 2;
                    has[new_mid].emplace_back(U, V, mx, id);
                }
                has[i].clear();
            }
        }
        if (br) break;
    }

    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "YES" : "NO") << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    auto start = chrono::steady_clock::now();
    if (TC) {
        cin >> TC;
        start = chrono::steady_clock::now();
        int TEST = 0;
        while (TEST < TC) {
            cerr << "[Testcase " << TEST + 1 << "]" << endl;
            solve();
            ++TEST;
        }
    } else
        solve();
#ifdef LOCAL_DEBUG
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "\nTime taken: ";
    cerr << chrono::duration<double, milli>(diff).count() << " ms" << endl;
#endif
}
