#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAX = 1.1e4;
vector<int> adj[MAX], adj2[MAX];

bool vis[MAX];
int dp[MAX], nc;
int prof[MAX];
int cc[MAX];
vector<pair<int, int>> edges;

void dfs(int u, int l = -1, int p = 0) {
    prof[u] = p;
    vis[u] = true;
    for (int v : adj[u]) {
        if (v == l) continue;
        if (vis[v]) {
            if (prof[v] < prof[u]) dp[v]--, dp[u]++;
        } else {
            dfs(v, u, p + 1);
            dp[u] += dp[v];
        }
    }
}

void dfs2(int u, int l = -1) {
    vis[u] = true;
    if (dp[u] == 0) {
        edges.emplace_back(l, u);
    }
    for (int v : adj[u]) {
        if (vis[v]) continue;
        dfs2(v, u);
    }
}

void dfs3(int u) {
    vis[u] = true;
    cc[u] = nc;
    for (int v : adj2[u]) {
        if (vis[v]) continue;
        dfs3(v);
    }
}

void solve(int n, int m, int q) {
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    edges.clear();
    for (int i = 0; i <= n; i++) dp[i] = prof[i] = vis[i] = 0;
    dfs(1);
    dp[1] = 1e9;
    for (int i = 0; i <= n; i++) vis[i] = 0;
    dfs2(1);
    for (auto [u, v] : edges) {
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }
    for (int i = 0; i <= n; i++) vis[i] = 0;
    nc = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs3(i);
            nc++;
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (cc[u] == cc[v] ? 'Y' : 'N') << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        int n, m, q;
        cin >> n >> m >> q;
        if (n == 0) break;
        solve(n, m, q);
        for (int i = 0; i <= n; i++) adj[i].clear(), adj2[i].clear();
        cout << "-\n";
    }
}
