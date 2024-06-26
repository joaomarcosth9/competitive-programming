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
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<vector<int>> adj(n * 2);

    for (int i = 0; i < n; i++) {
        adj[i].push_back((i + a[i]) % n + n);
    }

    for (int i = 0; i < n; i++) {
        adj[i + n].push_back((i + a[i]) % n + n);
        adj[i + n].push_back((i + 1) % n + n);
    }

    vector<int> dis(n * 2, -1);
    queue<int> q;
    q.push(0);
    dis[0] = 0;

    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dis[x + n] << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}