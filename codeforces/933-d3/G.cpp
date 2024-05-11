#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;
using i3 = tuple<int, int, int>;

const int N = 2e5 + 5;
int n, m;
vector<pair<int, int>> adj[N];

int conv[N];
vector<int> colors;

void solve() {
    cin >> n >> m;
    colors.clear();

    vector<i3> edges;
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--; v--; c--;
        colors.push_back(c);
        edges.push_back({u, v, c});
    }

    sort(colors.begin(), colors.end());
    colors.erase(unique(colors.begin(), colors.end()), colors.end());

    for (int i = 0; i < (int)colors.size(); i++) {
        conv[colors[i]] = (int)(lower_bound(colors.begin(), colors.end(), colors[i]) - colors.begin());
    }

    for (int i = 0; i < m; i++) {
        auto [u, v, c] = edges[i];
        adj[u].push_back({v, conv[c]});
        adj[v].push_back({u, conv[c]});
    }

    int s, t; cin >> s >> t;
    s--; t--;

    const int INF = 2e9;
    vector<map<int, ll>> dis(n);

    using T = tuple<ll, int, int>;
    deque<T> q;
    q.emplace_back(0, s, N);

    while (q.size()) {
        auto [w, u, c] = q.front();
        q.pop_front();
        if (dis[u].count(c)) continue;
        dis[u][c] = w;
        for (auto [v, cc] : adj[u]) {
            if (c == cc) {
                q.emplace_front(w, v, cc);
            } else {
                q.emplace_back(w + 1, v, cc);
            }
        }
    }

    debug(s, t);

    debug(dis);

    ll ans = LLONG_MAX;
    for (auto [c, d] : dis[t]) {
        ans = min(ans, d);
    }
    cout << ans << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
