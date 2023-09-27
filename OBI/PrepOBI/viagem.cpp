#include <bits/stdc++.h>

using namespace std;

#define int long long
const int MAX = 1e4 + 5;
typedef tuple<int, int, int> i3;

vector<i3> adj[MAX];
int dp[MAX][201];

void solve() {
    int v, n, m;
    cin >> v >> n >> m;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 201; j++) dp[i][j] = INT_MAX;
    for (int i = 0; i < m; i++) {
        int n1, n2, t, c;
        cin >> n1 >> n2 >> t >> c;
        adj[n1].emplace_back(n2, t, c);
        adj[n2].emplace_back(n1, t, c);
    }
    int sc, dest;
    cin >> sc >> dest;
    priority_queue<i3, vector<i3>, greater<i3>> pq;
    pq.emplace(sc, 0, 0);
    while (!pq.empty()) {
        auto [u, t, c] = pq.top();
        pq.pop();
        if (c > v || dp[u][c] < t) continue;
        dp[u][c] = min(dp[u][c], t);
        for (auto [vv, tt, cc] : adj[u]) {
            pq.emplace(vv, t + tt, c + cc);
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < 201; i++) {
        res = min(res, dp[dest][i]);
    }
    cout << res << endl;
}

signed main() {
    solve();
    return 0;
}
