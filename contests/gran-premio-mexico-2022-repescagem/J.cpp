#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 3e5 + 5;
int n;
long long arr[maxn], dp[maxn][2];
// dp[u][1] -> edge ta saindo de mim pro meu pai
// dp[u][0] -> edge ta saindo de do meu pai pra mim
vector<int> adj[maxn];

void dfs(int u, int p = -1) {
    if (adj[u].size() == 1 && p != -1) {
        dp[u][1] = arr[1], dp[u][0] = arr[0];
        return;
    }
    priority_queue<long long> pq;
    long long curr = 0;
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u);
            pq.push(dp[v][0] - dp[v][1]);
            curr += dp[v][1];
        }
    dp[u][0] = curr + arr[0];
    dp[u][1] = curr + arr[1];
    int i = 1;
    while (!pq.empty()) {
        curr += pq.top();
        if (i < n) dp[u][0] = max(dp[u][0], curr + arr[i]);
        if (i < n - 1) dp[u][1] = max(dp[u][1], curr + arr[i + 1]);
        i++;
        pq.pop();
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << dp[0][0] << endl;
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
