#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 2e5 + 5;

int n, q, a[N];
vector<pair<int, int>> adj[N];
tuple<int, int, int> edges[N];

namespace seg {
    pair<int, int> t[2 * N];

    void build() {
        for (int i = 0; i < n; i++) {
            t[i + n] = {a[i], i};
        }
        for (int i = n - 1; i > 0; i--) {
            t[i] = max(t[i << 1], t[i << 1 | 1]);
        }
    }

    void update(int i, int x) {
        t[i += n] = {x, i};
        for (i >>= 1; i > 0; i >>= 1) {
            t[i] = max(t[i << 1], t[i << 1 | 1]);
        }
    }

    pair<int, int> query(int l, int r) {
        pair<int, int> ans = {0, -1};
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, t[l++]);
            if (r & 1) ans = max(ans, t[--r]);
        }
        return ans;
    }
}

namespace hld {
    int t;
    int sz[N], head[N], par[N], pos[N], big[N];

    void dfs_sz(int u, int p = -1) {
        sz[u] = 1;
        for (auto [v, w] : adj[u]) {
            if (v != p) {
                dfs_sz(v, u);
                sz[u] += sz[v];
                if (big[u] == 0 || sz[v] > sz[big[u]]) {
                    big[u] = v;
                }
            }
        }
    }

    void dfs(int u, int p = -1) {
        pos[u] = t++;
        for (auto [v, w] : adj[u]) {
            if (v != p) {
                par[v] = u;
                head[v] = v == big[u] ? head[u] : v;
                dfs(v, u);
            }
        }
    }

    void build(int root) {
        dfs_sz(root);
        t = 0;
        head[root] = root;
        par[root] = -1;
        dfs(root);
        for (int i = 0; i < n - 1; i++) {
            auto [u, v, w] = edges[i];
            if (pos[u] > pos[v]) swap(u, v);
            // pos[u] < pos[v]
            a[v] = w;
        }
        seg::build();
    }

    pair<int, int> query(int u, int v) {
        if (pos[u] > pos[v]) {
            swap(u, v);
        }

        if (head[u] == head[v]) {
            return seg::query(pos[u] + 1, pos[v]);
        }
        pair<int, int> qv = seg::query(pos[head[v]], pos[v]);
        return max(qv, query(u, par[head[v]]));

    }

    void update(int u, int x) {
        seg::update(pos[u], x);
    }

}

void solve() {
    cin >> n >> q;

    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges[i] = {u, v, w};
        ans += w;
    }

    hld::build(0);

    while (q--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        auto [mx, where] = hld::query(u, v);
        debug(u, v, mx, where, w);
        if (w < mx) {
            ans += w - mx;
            hld::update(where, w);
        }
        cout << ans << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
