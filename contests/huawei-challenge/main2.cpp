#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)5e4 + 5;

vector<pair<int, int>> adj[N];
vector<pair<int, int>> edges;
map<int, int> adj2[N];
bool covered[N], proib[N];
int n, m;
int conv[N];

vector<vector<int>> ans;

bool vis[N];

vector<int> path, path_edges;
vector<int> poss, poss_edges;

void dfs(int u, int want) {
    vis[u] = 1;
    for (auto [v, id] : adj[u]) if (!proib[conv[id]]) {
        path.push_back(v);
        path_edges.push_back(conv[id]);
        if (!vis[v]) {
            dfs(v, want);
        } else if (v == want) {
            if (poss.empty() || path.size() < poss.size()) {
                poss = path;
                poss_edges = path_edges;
            }
        }
        path.pop_back();
        path_edges.pop_back();
    }
}

vector<pair<int, int>> input;

void solve() {

    for (int k = 0; k < m; k++) {
        int i = conv[k];
        if (covered[i]) continue;
        path.clear();
        path_edges.clear();
        poss.clear();
        poss_edges.clear();
        memset(vis, 0, (n + 1) * sizeof *vis);

        auto [u, v] = edges[i];
        path.push_back(v);
        path.push_back(u);
        path_edges.push_back(i);

        debug(u, v, path, path_edges);
        covered[i] = 1;
        proib[i] = 1;
        vis[v] = 1;

        dfs(u, v);

        if (poss.empty()) continue;

        debug(poss_edges);
        debug(poss);

        for (auto j : poss_edges) covered[j] = 1;
        ans.push_back(poss);
    }

    bool db = 1;
    for (int i = 0; i < m; i++) {
        debug(i, covered[i]);
        db &= covered[i];
    }
    if (!db) return;

    cout << ans.size() << endl;
    for (auto cyc : ans) {
        cout << cyc.size() << " ";
        for (int j = 0; j < (int)cyc.size(); j++) {
            cout << cyc[j] << " \n"[j == (int)cyc.size() - 1];
        }
    }
    exit(0);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        n = max({n, u, v});
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        edges.push_back({u, v});
    }
    for (int i = 0; i <= m; i++) {
        conv[i] = i;
    }
    while (true) {
        solve();
        shuffle(conv, conv + m, rng);
    }
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
