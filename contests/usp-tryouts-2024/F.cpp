#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
using i3 = tuple<int, int, int>;

const int N = 1e6 + 6;
int n, m;
i3 edges[N];
pair<int, int> edges_dir[N];
int d[N], edge_used[N], vis[N], vis2[N], ans[N];
vector<pair<int, int>> adj[N];

void dfs(int u) {
    vis[u] = 1;
    for (auto [v, id] : adj[u]) {
        if (!vis[v]) {
            dfs(v);
            if (d[v] == 1) {
                d[u] ^= 1, d[v] ^= 1;
                edge_used[id] = 1;
            }
        }
    }
}

void dfs2(int u) {
    vis2[u] = 1;
    while (adj[u].size()) {
        auto [v, id] = adj[u].back();
        adj[u].pop_back();
        if (!vis[id] && edge_used[id]) {
            vis[id] = 1;
            auto &[u2, v2] = edges_dir[id];
            if (u2 == u && v2 == v) {
                ans[id] = -1;
            } else {
                ans[id] = 1;
            }
            dfs2(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        u--; v--;
        edges[i] = {u, v, b};
        edges_dir[i] = {u, v};
        if (b == 1) {
            d[u] ^= 1, d[v] ^= 1;
            edge_used[i] = 1;
        } else {
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (d[i] == 1) {
                cout << "N" << endl;
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }

    for (int i = 0; i < m; i++) {
        auto &[u, v, b] = edges[i];
        if (edge_used[i]) {
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
    }

    memset(vis, 0, sizeof vis);

    for (int i = 0; i < n; i++) {
        if (!vis2[i]) {
            dfs2(i);
        }
    }

    cout << "S" << endl;

    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}