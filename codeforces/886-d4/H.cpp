#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 200200;

int n, m;
ll a[N];
int vis[N], dr;

vector<pair<int, int>> adj[N];

void dfs(int u, ll x = 0) {
    if (vis[u]) {
        dr |= x != a[u];
        return;
    }

    vis[u] = 1;
    a[u] = x;

    for (auto [v, w] : adj[u]) {
        dfs(v, x + w);
    }
}

void solve() {
    cin >> n >> m;
    dr = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, -w);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    cout << (dr ? "No" : "Yes") << endl;

    for (int i = 0; i < n; i++) {
        adj[i].clear();
        a[i] = vis[i] = 0;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
