#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;

const int maxn = 1.1e4, inf = 1e9 + 5;

vector<pair<int, int>> adj[maxn];
vector<int> adj2[maxn];
map<ii, int> cost;
bool vis[maxn];

ll res = 0;

ii uv(int u, int v) {
    if (u > v) swap(u, v);
    return make_pair(u, v);
}

void dfs(int u) {
    vis[u] = true;
    for (auto v : adj2[u]) {
        res += cost[uv(u, v)];
        if (vis[v] || v == -1) continue;
        dfs(v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    memset(vis, 0, n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == v) continue;
        int at = cost[uv(u, v)];
        if (at == 0 || at >= w) {
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
            cost[uv(u, v)] = w;
        }
    }
    priority_queue<iii, vector<iii>, greater<iii>> pq;
    vector<pair<int, vector<int>>> dis(n, make_pair(inf, vector<int>(0)));
    pq.emplace(0, make_pair(0, -1));
    while (!pq.empty()) {
        auto wu = pq.top();
        int w = wu.first, u = wu.second.first, pu = wu.second.second;
        pq.pop();
        if (w == dis[u].first) {
            dis[u].second.push_back(pu);
        } else if (w < dis[u].first) {
            dis[u].first = w;
            dis[u].second.clear();
            if (pu != -1) dis[u].second.push_back(pu);
            for (auto wwv : adj[u]) {
                int ww = wwv.first, v = wwv.second;
                pq.emplace(w + ww, make_pair(v, u));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        adj2[i] = dis[i].second;
    }
    dfs(n - 1);
    cout << res * 2 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
