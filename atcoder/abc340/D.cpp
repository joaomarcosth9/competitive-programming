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
    int n; cin >> n;
    vector<int> a(n), b(n), x(n);
    vector<vector<pair<ll, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i] >> x[i];
        x[i]--;
        adj[i].push_back({a[i], i + 1});
        adj[i].push_back({b[i], x[i]});
    }
    const ll INF = 1e18;
    vector<ll> dis(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.emplace(0, 0);
    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (dis[u] <= w) continue;
        dis[u] = w;
        for (auto [ww, v] : adj[u]) {
            if (dis[v] > w + ww) {
                pq.emplace(w + ww, v);
            }
        }
    }
    cout << dis[n - 1] << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
