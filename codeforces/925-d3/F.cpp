#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 2e5 + 5;
set<int> adj[N];
int vis[N];
bool dp[N];

vector<int> topo;
void toposort(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) {
        toposort(v);
    }
    topo.push_back(u);
}

bool solve() {
    topo.clear();
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int p; cin >> p;
        vector<int> now(n - 1);
        for (int j = 0; j < n - 1; j++) {
            cin >> now[j];
        }
        for (int j = 0; j < n - 2; j++) {
            adj[now[j]].insert(now[j + 1]);
        }
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        toposort(i);
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }
    bool db = 1;
    for (auto u : topo) {
        dp[u] = 1;
        for (auto v : adj[u]) {
            dp[u] &= dp[v];
        }
        db &= dp[u];
    }
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        vis[i] = 0;
        dp[i] = 0;
    }
    return db;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "Yes" : "No") << endl;
    }
}
