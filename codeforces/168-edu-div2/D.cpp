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
    int n; cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        adj[p - 1].push_back(i);
    }

    /*
        pra um cara em especifico, posso fazer min[u] operacoes nele, mas depois, nenhum pai dele pode fazer operacao tb
        // se a[u] < min[u], posso equalizar ao maximo os dois
    */

    function<ll(int)> dfs = [&] (int u) -> ll {
        ll min_sub = LLONG_MAX;
        for (int v : adj[u]) {
            min_sub = min(min_sub, dfs(v));
        }
        if (u == 0) {
            a[u] += min_sub;
            return a[u];
        }
        if (min_sub != LLONG_MAX) {
            if (min_sub > a[u]) {
                ll d = min_sub - a[u];
                min_sub -= (d + 1) / 2;
                a[u] += (d + 1) / 2;
            }
            assert(a[u] >= min_sub);
        }
        return min(min_sub, a[u]);
    };

    cout << dfs(0) << endl;
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