#include <bits/stdc++.h>
using namespace std;

// dijkstra (int source, int number_of_nodes, vector<vii>& adj);
const int MAXN = 2e5;
int dist[MAXN];
void dijkstra(int source, int n_nodes, vector<vector<pair<int, int>>> &Adj) {
    for (int i = 0; i <= n_nodes + 3; i++) dist[i] = 2123456789;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        auto [w, s] = pq.top();
        pq.pop();
        if (dist[s] > w) {
            dist[s] = w;
            for (int i = 0; i < (int)Adj[s].size(); i++) {
                auto [ww, dest] = Adj[s][i];
                if (ww + w < dist[dest]) pq.push({w + ww, dest});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> Adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Adj[a].push_back({c, b});
        Adj[b].push_back({c, a});
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto a : Adj[i]) {
            cout << a.second << " ";
        }
        cout << endl;
    }
    int u;
    cin >> u;
    dijkstra(u, n, Adj);
    int minn = INT_MAX;
    int maxx = INT_MIN;
    for (int i = 1; i <= n; i++)
        if (i != u) {
            cout << i << " " << dist[i] << endl;
            minn = min(minn, dist[i]);
            maxx = max(maxx, dist[i]);
        }
    cout << maxx - minn << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
