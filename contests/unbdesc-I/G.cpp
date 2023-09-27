#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int maxn = 2e5 + 5;
int arr[maxn];
bool vis[maxn];
vector<int> adj[maxn];

int dfs(int u, int p = -1) {
    if (vis[u]) return 0;
    vis[u] = 1;
    for (int v : adj[u])
        if (v != p) {
            arr[u] += dfs(v, u);
        }
    return arr[u];
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        adj[p - 1].emplace_back(i);
    }
    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;
        arr[d - 1]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        u--;
        cout << dfs(u) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
