#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct DSU {
    vector<int> par, sz;
    int number_of_sets;
    DSU(int n = 0) : par(n), sz(n, 1), number_of_sets(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) {
            return false;
        }
        number_of_sets--;
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

const int N = 16;
int n, m;
int dist[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = -c;
        debug(a, b, dist[a][b]);
    }

    DSU d(n);

    vector<int> vis(n);

    vector<pair<int, vector<int>>> masks;

    for (int i = 0; i < n; i++) {
        if (vis[d.find(i)]) continue;
        for (int p = 0; p < n; p++) {
            bool imp = false;
            vector<int> pos(n, -1);
            pos[i] = p;
            vector<int> who(n, -1);
            who[p] = i;
            vector<int> guys = {i};
            while (true) {
                bool changed = false;
                vector<int> new_guys;   
                for (auto u : guys) {
                    for (int v = 0; v < n; v++) if (pos[v] == -1 && dist[u][v] != 0) {
                        pos[v] = pos[u] + dist[v][u];
                        if (pos[v] < 0 || pos[v] >= n || who[pos[v]] != -1) {
                            imp = true;
                            break;
                        }
                        who[pos[v]] = v;
                        new_guys.push_back(v);
                        changed = true;
                    }
                    if (imp) break;
                }
                if (!changed || imp) break;
                guys = new_guys;
            }

            if (imp) continue;

            assert(who[0] != -1);

            int used_positions = 0;
            vector<int> guys2;
            for (int j = 0; j < n; j++) {
                if (who[j] != -1) {
                    used_positions |= 1 << j;
                    guys2.push_back(who[j]);
                }
            }

            for (auto u : guys) {
                d.unite(i, u);
            }
            vis[d.find(i)] = 1;

            masks.push_back({used_positions, guys2});

            break;
        }
    }

    for (auto u : masks) {
        debug(bin(u.first, n), u.second);
    }

    for (int i = 0; i < n; i++) {
        debug(i, d.find(i));
    }

    int nmasks = (int)masks.size();

    vector<int> ans(n, -2);

    for (int i = 0; i < nmasks; i++) {
        for (int pos = 0; pos < n; pos++) {
            // 16 ^ 2
            vector<int> dp(1 << n, 0);
            int actual = (masks[i].first << pos);
            if (actual >> n) continue;
            debug(i, pos, bin(actual, n));
            dp[actual] = 1;
            for (int j = 0; j < nmasks; j++) {
                // 16
                if (i == j) continue;
                auto ndp = dp;
                for (int posj = 0; posj < n; posj++) {
                    // 16
                    auto &[mask, _] = masks[j];
                    actual = (mask << posj);
                    if (actual >> n) continue;
                    debug(j, bin(actual, n));
                    for (int msk = 0; msk < (1 << n); msk++) {
                        // 2 ^ 16
                        if ((msk & actual) == 0) {
                            ndp[msk | actual] |= dp[msk];
                        }
                    }
                }
                dp = ndp;
            }
            if (dp[(1 << n) - 1]) {
                auto &[mask, guys] = masks[i];
                int it_guys = 0;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) {
                        if (ans[guys[it_guys]] == -2) {
                            ans[guys[it_guys]] = j + pos;
                        } else {
                            ans[guys[it_guys]] = -1;
                        }
                        it_guys++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << (ans[i] == -1 ? -1 : ans[i] + 1) << " ";
    }
    cout << endl;

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
