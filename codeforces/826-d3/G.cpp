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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<vector<int>> lives(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    int f; cin >> f;
    vector<int> house(f);

    for (int i = 0; i < f; i++) {
        int h;
        cin >> h;
        h--;
        house[i] = h;
        lives[h].emplace_back(i);
    }

    int k;
    cin >> k;

    vector<int> conv(f, -1);

    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;
        u--;
        conv[u] = i;
    }

    vector dis(n, vector<int> (1 << k, -1));

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);

    while (!q.empty()) {
        auto [d, u, msk] = q.front();
        q.pop();
        if (dis[u][msk] != -1) continue;
        dis[u][msk] = d;
        for (int v : adj[u]) {
            if (dis[v][msk] != -1) continue;
            q.emplace(d + 1, v, msk);
        }

        for (auto v : lives[u]) {
            if (conv[v] == -1) continue;
            msk |= (1 << conv[v]);
        }
        if (dis[u][msk] != -1) continue;
        dis[u][msk] = d;

        for (int v : adj[u]) {
            if (dis[v][msk] != -1) continue;
            q.emplace(d + 1, v, msk);
        }
    }

    vector<int> done(1 << k);
    done[0] = 1;

    for (int l = 0; l < f; l++) if (conv[l] == -1) {
        int i = house[l];
        int mn = INT_MAX;
        for (int j = 0; j < (1 << k); j++) {
            if (dis[i][j] == -1) continue;
            mn = min(mn, dis[i][j]);
        }
        auto ndone = done;
        for (int j = 0; j < (1 << k); j++) {
            if (dis[i][j] == -1) continue;
            if (dis[i][j] == mn) {
                for (int msk = 0; msk < (1 << k); msk++) {
                    ndone[msk | j] |= done[msk];
                }
            }
        }
        swap(done, ndone);
    }

    int res = k;
    for (int i = 0; i < (1 << k); i++) {
        if (done[i]) {
            res = min(res, k - __builtin_popcount(i));
        }
    }

    cout << res << endl;
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
