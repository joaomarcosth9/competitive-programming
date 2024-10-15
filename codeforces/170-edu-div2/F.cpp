#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 300300;

int deg[N], ans[N], vis[N];
pair<int, int> edge[N];
vector<pair<int, int>> adj[N];

void dfs(int u, int p) {
    vis[u] = 1;
    for (auto [v, i] : adj[u]) {
        if (v != p && !vis[v]) {
            dfs(v, u);
            if (deg[v] == 1) {
                ans[i] ^= 1;
                deg[v] ^= 1;
                deg[u] ^= 1;
            }
        }
    }
}

int a[N];

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back({v, i});
        adj[v].push_back({u, i});

        edge[i] = {u, v};
        deg[v] ^= 1;

        ans[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, i);
        }
    }

    for (int i = 0; i < q; i++) {
        auto [u, v] = edge[i];

        string f = "y";

        if (ans[i] == 0) {
            swap(u, v);
            f = "x";
        }

        // u -> v
        if (a[v] == 1) {
            f += "-";
        } else {
            f += "+";
        }


        a[v] ^= 1;

        cout << f << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}