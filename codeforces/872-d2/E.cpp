#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

const int maxn = 1e5 + 5;
int arr[maxn];
vector<int> adj[maxn];
int res = 0;

pair<int, int> dfs(int u = 0, int p = -1) {
    set<int> st;
    for (int v : adj[u])
        if (v != p) {
            auto [x, b] = dfs(v, u);
            st.insert(x);
        }
    return arr[u];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs();
    cout << res << '\n';
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
