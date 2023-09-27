#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 2e5 + 5;
int n, q;
long long arr[maxn], sz[maxn], par[maxn];
vector<int> adj[maxn];
set<pair<long long, int>> adj2[maxn];
long long imp[maxn];

pair<long long, long long> dfs(int u, int p = -1) {
    par[u] = p;
    imp[u] = arr[u];
    sz[u] = -1;
    for (int v : adj[u])
        if (v != p) {
            auto [_imp, _sz] = dfs(v, u);
            imp[u] += _imp;
            sz[u] += _sz;
        }
    return {imp[u], sz[u]};
}

void rotate(int u) {
    if (adj2[u].empty()) return;
    auto [szson, sonu] = *(adj2[u].begin());
    // sonu is the heavy son of u

    int oldszu = sz[u];
    int oldszsonu = sz[sonu];

    sz[u] -= oldszsonu;
    sz[sonu] = oldszu;

    long long oldimpu = imp[u];
    imp[u] -= imp[sonu];
    imp[sonu] = oldimpu;

    adj2[par[u]].erase(make_pair(oldszu, u));
    adj2[par[u]].emplace(oldszu, sonu);

    adj2[u].erase(make_pair(oldszsonu, sonu));
    adj2[sonu].emplace(sz[u], u);

    int oldparu = par[u];
    par[u] = sonu;
    par[sonu] = oldparu;
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(0);
    for (int i = 1; i < n; i++) {
        adj2[par[i]].emplace(sz[i], i);
    }
    for (int i = 0; i < n; i++) {
        db(i, adj2[i]);
    }
    while (q--) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            cout << imp[x] << endl;
        } else if (t == 2) {
            rotate(x);
        }
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
