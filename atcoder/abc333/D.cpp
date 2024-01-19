#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 300300;
vector<int> adj[N];
int n, dp[N];

void dfs(int u, int p = -1) {
    dp[u] = 1;
    vector<int> children;
    for (auto v : adj[u]) if (v != p) {
        dfs(v, u);
        children.emplace_back(v);
        if (p != -1) dp[u] += dp[v];
    }
    if (p == -1) {
        sort(begin(children), end(children), [&] (int i, int j) {
            return dp[i] < dp[j];
        });
        for (int i = 0; i < (int)children.size() - 1; i++) dp[u] += dp[children[i]];
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(0);
    cout << dp[0] << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
