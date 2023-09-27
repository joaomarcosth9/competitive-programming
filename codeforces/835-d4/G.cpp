#include <bits/stdc++.h>

using namespace std;

int testcases = 1;
const int INF = 1.05e9;
const long long INFLL = 4.5e18;
const int MAX = 1.1e5;
int n, s, d;
vector<pair<int, int>> adj[MAX];
map<int, bool> has, vis;

void dfs(int u, int current) {
    if (u != d) has[current] = true;
    vis[u] = true;
    for (auto [v, w] : adj[u]) {
        if (v == d || vis[v]) continue;
        dfs(v, current ^ w);
    }
}

void solve() {
    cin >> n >> s >> d;
    s--, d--;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(s, 0);
    map<int, bool> has1 = has;
    has.clear();
    vis.clear();
    dfs(d, 0);
    int db = 0;
    for (auto [k, v] : has) {
        if (has1[k]) db = 1;
    }
    cout << (db ? "YES" : "NO") << endl;
    for (int i = 0; i <= n; i++) adj[i].clear();
    has.clear();
    vis.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
