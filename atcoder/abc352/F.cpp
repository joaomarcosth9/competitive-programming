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
int msk[N][N];

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

    vector<pair<int, int>> masks;

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

            int used_positions = 0;
            for (int j = 0; j < n; j++) {
                if (who[j] != -1) used_positions |= 1 << j;
            }

            for (auto u : guys) {
                d.unite(i, u);
            }
            vis[d.find(i)] = 1;

            masks.push_back({used_positions, i});

            break;
        }
    }

    for (auto u : masks) {
        debug(bin(u.first, n), u.second);
    }

    int nmasks = (int)masks.size();

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int sub = mask; sub; sub = (sub - 1) & mask) {

        }
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
