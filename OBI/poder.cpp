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

    function<bool(int, int)> valid = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    vector<pair<int, int>> moves = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    function<int(int, int)> node = [&] (int i, int j) {
        return i * m + j;
    };

    function<pair<int, int>(int)> get = [&] (int nd) {
        return pair<int, int>(nd / m, nd % m);
    };

    vector a(n, vector<int> (m));

    for (auto &u : a) {
        for (auto &v : u) {
            cin >> v;
        }
    }

    vector<tuple<int, int, int>> all;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            all.push_back({a[i][j], i, j});
        }
    }

    sort(begin(all), end(all));

    int N = n * m;

    vector<int> par(N), dsu_par(N), sz(N);
    vector<pair<int, int>> mx(N);

    for (int i = 0; i < N; i++) {
        par[i] = dsu_par[i] = i;
        sz[i] = 1;
        mx[i] = get(i);
    }

    function<int(int)> find = [&] (int u) {
        return u == dsu_par[u] ? u : dsu_par[u] = find(dsu_par[u]);
    };

    function<void(int, int, int, int)> unite = [&] (int ni, int nj, int i, int j) {
        assert(a[i][j] >= a[ni][nj]);
        int u = node(ni, nj), v = node(i, j);
        u = find(u), v = find(v);

        // dsu 2 ? 
        int u2 = node(mx[u].first, mx[u].second);
        int v2 = node(mx[v].first, mx[v].second);
        debug(u2, a[mx[u].first][mx[u].second], v2, a[mx[v].first][mx[v].second]);
        par[u2] = v2;

        // dsu normal
        if (u == v) {
            return;
        }
        if (sz[u] < sz[v]) {
            swap(u, v);
        }
        sz[u] += sz[v];
        dsu_par[v] = u;
        if (a[mx[v].first][mx[v].second] > a[mx[u].first][mx[u].second]) {
            mx[u] = mx[v];
        }
    };

    for (auto [val, i, j] : all) {
        debug(val, i, j);
        for (auto [x, y] : moves) {
            int ni = i + x, nj = j + y;
            if (!valid(ni, nj) || a[ni][nj] > a[i][j]) continue;
            debug("unindo", i, j, a[i][j], ni, nj, a[ni][nj]);
            unite(ni, nj, i, j);
        }
    }

    for (auto [val, i, j] : all) {
        debug(i, j, node(i, j), get(par[node(i, j)]));
    }

}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}