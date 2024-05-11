#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = (int)5e4 + 5;

vector<pair<int, int>> adj[N];
vector<pair<int, int>> edges;
map<int, int> adj2[N];
bool covered[N];
int n, m, cnt = 0;

vector<vector<int>> ans;

bool vis[N];

vector<int> path, path_edges;
bool db = 0;

void dfs(int u, int want, int last) {
    vis[u] = 1;
    if (db) return;
    debug(u, want, last, path, path_edges, db);
    for (auto [v, id] : adj[u]) if (v != last) {
        if (!vis[v]) {
            path.push_back(v);
            path_edges.push_back(id);
            dfs(v, want, u);
            if (db) return;
            path.pop_back();
            path_edges.pop_back();
        } else if (v == want) {
            if (!db) {
                /* debug("DB", path, path_edges); */
                path.push_back(v);
                path_edges.push_back(id);
                for (auto j : path_edges) {
                    covered[j] = 1;
                }
                ans.push_back(path);
                db = 1;
                return;
            }
        }
        if (db) return;
    }
}

void solve() {
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        n = max({n, u, v});
        if (u > v) swap(u, v);
        if (adj2[u][v]) continue;
        adj2[u][v]++;
        adj[u].push_back({v, cnt});
        adj[v].push_back({u, cnt});
        edges.push_back({u, v});
        cnt++;
    }

    m = cnt;

    /* debug(edges); */

    for (int i = 0; i < m; i++) {
        if (covered[i]) continue;

        path.clear();
        path_edges.clear();
        db = 0;
        memset(vis, 0, (n + 1) * sizeof *vis);

        auto [u, v] = edges[i];
        path.push_back(v);
        path.push_back(u);
        path_edges.push_back(i);

        debug(u, v, path, path_edges);
        vis[v] = 1;
        dfs(u, v, v);
    }

    for (int i = 0; i < m; i++) {
        debug(i, edges[i], covered[i]);
    }

    cout << ans.size() << endl;
    for (auto cyc : ans) {
        cout << cyc.size() << " ";
        for (int j = 0; j < (int)cyc.size(); j++) {
            cout << cyc[j] << " \n"[j == (int)cyc.size() - 1];
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
