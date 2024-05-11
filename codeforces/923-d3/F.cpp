#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
using ii = pair<int, int>;
using i3 = tuple<int, int, int>;

const int N = 2e5 + 5;
int n, m;
bool vis[N];
int dp[N], dep[N];
vector<i3> adj2[N];
vector<ii> adj[N];
bool is_bridge[N];

void dfs_dp(int u, int p = -1, int d = 0, int ep = -1, int epid = -1) {
    dp[u] = 0, dep[u] = d, vis[u] = 1;
    for (auto [v, w, id] : adj2[u]) {
        if (v != p) {
            if (vis[v]) {
                if (dep[v] < dep[u]) dp[v]--, dp[u]++;
            } else {
                dfs_dp(v, u, d + 1, w, id);
                dp[u] += dp[v];
            }
        }
    }
    if (dp[u] == 0 && p != -1) { // edge {u, p} eh uma ponte
        is_bridge[epid] = 1;
    }
}

void find_bridges() {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs_dp(i);
        }
    }
}

vector<int> res;
bool ok = 0;
int best, s, t;

void dfs(int u) {
    if (ok) return;

    vis[u] = 1;
    res.push_back(u);

    if (u == t) {
        ok = 1;
        return;
    }
    if (ok) return;

    for (auto [v, w] : adj[u]) if (!vis[v]) {
        if (u == s && v == t) continue;
        dfs(v);
        if (ok) return;
    }
    if (ok) return;

    res.pop_back();
}

i3 edges[N];

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj2[u].push_back({v, w, i});
        adj2[v].push_back({u, w, i});
        edges[i] = {u, v, w};
    }

    find_bridges();
    
    memset(vis, 0, n * sizeof *vis);

    best = 1e9, s = -1, t = -1;

    for (int i = 0; i < m; i++) {
        if (!is_bridge[i]) {
            auto [u, v, w] = edges[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            if (w < best) {
                best = w;
                s = u, t = v;
            }
        }
    }

    dfs(s);

    cout << best << " ";
    cout << res.size() << endl;
    for (auto u : res) cout << (u + 1) << " ";
    cout << endl;
    cout << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            adj2[i].clear();
            vis[i] = 0;
        }
        ok = 0;
        for (int i = 0; i <= m; i++) {
            edges[i] = {0, 0, 0};
            is_bridge[i] = 0;
        }
        res.clear();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
