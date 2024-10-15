#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
#define int ll
const ll INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    int lim, t1, t2;
    cin >> lim >> t1 >> t2;

    using i3 = tuple<int, int, int>;
    using ii = pair<ll, int>;

    vector<vector<i3>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, l1, l2;
        cin >> u >> v >> l1 >> l2;
        u--; v--;
        adj[u].push_back({l1, l2, v});
        adj[v].push_back({l1, l2, u});
    }

    vector<ll> dis(n);

    function<void(int)> dijkstra = [&] (int s) {
        for (int i = 0; i < n; i++) {
            dis[i] = INF;
        }
        priority_queue<ii, vector<ii>, greater<>> pq;

        dis[s] = 0;
        pq.emplace(dis[s], s);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u]) {
                continue;
            }
            for (auto [l1, l2, v] : adj[u]) {
                if (d < t1 || d >= t2) {
                    if (d + l1 <= t1 || (d >= t2 && d + l1 <= lim)) {
                        if (dis[v] > d + l1) {
                            dis[v] = d + l1;
                            pq.emplace(dis[v], v);
                        }
                    }
                }
                if (d <= t2 && dis[v] > t2 + l1) {
                    dis[v] = t2 + l1;
                    pq.emplace(dis[v], v);
                }
                if (dis[v] > d + l2) {
                    dis[v] = d + l2;
                    pq.emplace(dis[v], v);
                }
            }
        }
    };

    dijkstra(0);
    debug(dis);
    swap(t1, t2);
    t1 = lim - t1;
    t2 = lim - t2;
    dijkstra(n - 1);
    debug(dis);

    cout << (lim >= dis[n - 1] ? lim - dis[n - 1] : -1) << endl;
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