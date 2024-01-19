#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int N = 100100;
int n, q;
vector<int> adj[N];
int head[N], pos[N], sz[N], par[N];

void dfs_sz(int u = 0, int p = -1) {
    sz[u] = 1;
    par[u] = p;
    for (int& v : adj[u]) {
        if (v != p) {
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]]) {
                swap(v, adj[u][0]);
            }
        }
    }
}

int T = 0;
void dfs_hld(int u = 0, int p = -1) {
    pos[u] = T++;
    for (int v : adj[u]) {
        if (v != p) {
            if (v == adj[u][0]) {
                head[v] = head[u];
            } else {
                head[v] = v;
            }
            dfs_hld(v, u);
        }
    }
}

pair<int, int> chains[N];

void query(int u, int v, bool clean) {
    if (pos[u] > pos[v]) {
        swap(u, v);
    }
    if (head[u] == head[v]) {
        if (not clean) chains[head[u]] = {pos[u], pos[v]};
        else chains[head[u]] = {-1, -1};
    } else {
        if (not clean) chains[head[v]] = {pos[head[v]], pos[v]};
        else chains[head[v]] = {-1, -1};
        query(u, par[head[v]], clean);
    }
}

int intersect(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (r1 < l2) {
        return 0;
    }
    if (r1 < r2) {
        return (r1 - l2 + 1);
    }
    return (r2 - l2 + 1);
}

void ans(int u, int v, int &res) {
    if (pos[u] > pos[v]) {
        swap(u, v);
    }
    if (head[u] == head[v]) {
        res += intersect(chains[head[u]].first, chains[head[u]].second, pos[u], pos[v]);
    } else {
        res += intersect(chains[head[v]].first, chains[head[v]].second, pos[head[v]], pos[v]);
        ans(u, par[head[v]], res);
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) chains[i] = {-1, -1};

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs_sz();
    head[0] = 0;
    dfs_hld();

    while (q--) {
        int u, v, uu, vv;
        cin >> u >> v; u--; v--;
        cin >> uu >> vv; uu--; vv--;

        int res = 0;

        query(u, v, 0);

        ans(uu, vv, res);

        query(u, v, 1);

        cout << res << endl;
    }
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
