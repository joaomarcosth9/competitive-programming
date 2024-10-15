#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; i++) {
        g[i].push_back(i + 1);
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (v > u + 1) {
            g[u].push_back(v);
        }
    }

    const int INF = 1e9;
    vector<int> dis(n, INF);

    queue<int> q;
    q.push(0);
    dis[0] = 0;

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dis[v] == INF) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    vector<int> dr(n + 1);

    for (int i = 1; i < n; i++) {
        // olho as arestas que começam em i - 1
        for (auto v1 : g[i - 1]) {
            if (v1 == i) continue;
            // todos os nodos de []
            // chego em v1 - u, ele chega em dis[i - 1] + 1
            // pra ele me pegar, v1 - u > dis[i - 1] + 1
            // u < v1 - dis[i - 1] - 1
            if (i < v1 - dis[i - 1] - 1) {
                dr[i]++;
                dr[v1 - dis[i - 1] - 1]--;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        dr[i] += dr[i - 1];
    }

    for (int i = 0; i < n - 1; i++) {
        cout << (dr[i] == 0);
    }
    cout << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}
