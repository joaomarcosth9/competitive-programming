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
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    const int INF = 1e9;

    set<int> pq;
    vector<int> dis(n, INF);

    pq.insert(0);

    while (pq.size()) {
        int u = *pq.begin();
        pq.erase(pq.begin());

        cout << (u + 1) << " ";
        dis[u] = 0;

        queue<int> q;
        q.push(u);

        while (q.size()) {
            u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (dis[v] > dis[u] + 1 && dis[u] + 1 <= k) {
                    dis[v] = dis[u] + 1;
                    pq.insert(v);
                    q.push(v);
                }
            }
        }
    }
    cout << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
