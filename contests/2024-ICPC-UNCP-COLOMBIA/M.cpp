#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e6 + 5;
int n;
vector<int> adj[N];
int par[N], dis[N], ts[N];

int bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    ts[s] = t;
    par[s] = -1;
    int mx = s;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (ts[v] < t) {
                dis[v] = dis[u] + 1;
                if (dis[v] > dis[mx]) {
                    mx = v;
                }
                ts[v] = t;
                par[v] = u;
                q.push(v);
            }
        }
    }
    return mx;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int mx = bfs(0, 1);

    mx = bfs(mx, 2);

    vector<int> diam;
    int u = mx;
    while (u != -1) {
        diam.push_back(u);
        u = par[u];
    }

    string res(n, '1');

    int D = (int)diam.size();

    if (diam.size() & 1) {
        res[diam[D / 2]] = '0';
    }

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}