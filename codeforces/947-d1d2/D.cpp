#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 3e5 + 5, LG = 20;
int n;
vector<int> adj[N];
int pa, pb;

namespace bl {
    int t, up[N][LG], tin[N], tout[N];
    int dep[N], sz[N], max_depth[N];

    void dfs(int u, int p = -1, int d = 0) {
        sz[u] = 1;
        tin[u] = t++;
        dep[u] = d;
        max_depth[u] = d;
        for (int i = 0; i < LG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
        }
        for (int v : adj[u])
            if (v != p) {
                up[v][0] = u;
                dfs(v, u, d + 1);
                sz[u] += sz[v];
                max_depth[u] = max(max_depth[u], max_depth[v]);
            }
        tout[u] = t++;
    }

    void build(int root) {
        t = 1;
        up[root][0] = root;
        dfs(root);
    }

    bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

    int lca(int u, int v) {
        if (ancestor(u, v))
            return u;
        if (ancestor(v, u))
            return v;
        for (int i = LG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    int kth(int u, int k) {
        for (int i = 0; i < LG; i++) {
            if (k & (1 << i)) {
                u = up[u][i];
            }
        }
        return u;
    }

}

void solve() {
    cin >> n;
    cin >> pa >> pb;
    pa--; pb--;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bl::build(pa);

    int d = bl::dist(pa, pb);

    int res = 0;

    int nd = bl::kth(pb, (d + 1) / 2);
    res += d / 2;

    bl::build(nd);

    res += 2 * bl::sz[nd] - bl::max_depth[nd] - 1;

    cout << res + (d & 1) - 1 << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
        }
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
