#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 2.1e5;
int n, m;
vector<int> adj[maxn];
bool vis[maxn];

pair<int, int> dfs2(int u) {
    vis[u] = 1;
    int r = 0;
    int f4 = -1;
    for (int v : adj[u]) {
        if (adj[v].size() == 4) {
            f4 = v;
            continue;
        }
        if (!vis[v] && adj[v].size() == 2) {
            auto [_r, _f4] = dfs2(v);
            r += _r;
            if (f4 == -1)
                f4 = _f4;
            else {
                if (f4 != _f4) {
                    f4 = -1;
                }
            }
        }
    }
    return {r + 1, f4};
}

int dfs4(int u) {
    vis[u] = 1;
    int r = 0;
    for (int v : adj[u])
        if (!vis[v] && adj[v].size() == 4) {
            r += dfs4(v);
        }
    return r + 1;
}

void solve() {
    cin >> n >> m;
    /* n = k + (k-1)*k = k + k^2 -k = k^2 */
    /* k = sqrt(n) */
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int L = 1, R = n;
    int k = -1;
    while (L <= R) {
        long long mid = (L + R) / 2;
        if (mid * mid <= n) {
            k = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    if (k < 3 || k * k != n || m != k * (k + 1)) {
        cout << "NO" << endl;
        return;
    }
    bool db = 1;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 2 && !vis[i]) {
            auto [r, f4] = dfs2(i);
            db(2, i + 1, r, f4);
            db &= (r == k - 1);
            db(db);
            db &= f4 != -1;
        } else if (adj[i].size() == 4 && !vis[i]) {
            int r = dfs4(i);
            db(4, i + 1, r);
            db(db);
            db &= (r == k);
        } else if (adj[i].size() != 2 && adj[i].size() != 4) {
            db = 0;
            break;
        }
    }
    cout << (db ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) {
            solve();
            for (int i = 0; i <= n; i++) {
                adj[i].clear();
            }
            memset(vis, 0, n + 1);
        }
    } else
        solve();
    return 0;
}
