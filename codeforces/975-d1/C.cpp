#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<set<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<int> dist_to_non_leaf(n), dep(n), par(n);
    vector<bool> leaf(n, false);

    auto dfs = [&] (auto&& self, int u, int p = -1, int d = 0) -> void {
        leaf[u] = true;
        dep[u] = d;
        par[u] = p;
        if (p != -1) adj[u].erase(p);
        for (int v : adj[u]) {
            assert(v != p);
            leaf[u] = false;
            self(self, v, u, d + 1);
        }
    };

    dfs(dfs, 0);

    set<pair<int, int>> lvs;

    for (int i = 0; i < n; i++) {
        if (leaf[i]) {
            lvs.insert({dep[i], i});
        }
    }

    vector<int> pref(n + 1), suf(n + 1);

    auto prev_adj = adj;

    vector<int> cost_up(n + 1), cost_down(n + 1);

    while (lvs.size()) {
        auto [d, u] = *lvs.rbegin();
        lvs.erase(--lvs.end());
        if (u == 0) break;
        // folha mais profunda

        debug(d, u);

        cost_up[d]++;

        assert(adj[par[u]].count(u));

        adj[par[u]].erase(u);

        if ((int)adj[par[u]].empty()) {
            assert(dep[par[u]] == d - 1);
            lvs.insert({d - 1, par[u]});
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + cost_up[i];
    }
    debug(cost_up);

    adj = prev_adj;

    lvs.clear();

    for (int i = 0; i < n; i++) {
        if (leaf[i]) {
            lvs.insert({dep[i], i});
        }
    }

    while (lvs.size()) {
        auto [orig, u] = *lvs.begin();
        lvs.erase(lvs.begin());
        if (u == 0) break;

        assert(adj[u].empty());
        // folha menos profunda

        debug(orig, u);

        cost_down[orig]++;

        assert(adj[par[u]].count(u));

        adj[par[u]].erase(u);

        if ((int)adj[par[u]].empty()) {
            lvs.insert({orig, par[u]});
        }
    }

    debug(cost_down);

    // suf[i] custo pra podar todas as folhas de dep >= i ate terem dep i-1 ou virarem nao folhas
    // pref[i] custo pra podar todas as folhas de dep <= i ate virarem nao folhas

    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + cost_down[i];
    }

    int ans = INT_MAX;

    for (int i = 1; i < n; i++) {
        debug(ans, i, pref[i - 1], suf[i + 1]);
        ans = min(ans, pref[i - 1] + suf[i + 1]);
    }

    assert(ans < INT_MAX);

    cout << ans << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        // cout << solve() << endl;
        // cout << (solve() ? "Yes" : "No") << endl;
    }
}