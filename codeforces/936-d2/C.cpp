#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 1e5 + 5;
int n, k;
vector<int> adj[N];
int cuts = 0;

int dfs(int u, int p, int val) {
    int ret = 1;
    for (int v : adj[u]) if (v != p) {
        int rv = dfs(v, u, val);
        if (rv < val) {
            ret += rv;
        } else {
            if (cuts < k) cuts++;
            else ret += rv;
        }
    }
    return ret;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l = 1, r = n;
    int ans = -1;
    while (l <= r) {
        cuts = 0;
        int mid = (l + r) / 2;
        int ret = dfs(0, 0, mid);
        if (ret >= mid && cuts == k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
