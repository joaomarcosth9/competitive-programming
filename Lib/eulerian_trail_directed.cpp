#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

const int MAXN = 1e6 + 6;

vector<int> adj[MAXN];

struct EulerianTrail {
    int n;
    int it[MAXN], deg_in[MAXN], deg_out[MAXN];
    void build(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            it[i] = deg_in[i] = deg_out[i] = 0;
        }
    }
    vector<int> find() {
        vector<int> cur;
        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j : adj[i]) {
                m++;
                deg_out[i]++, deg_in[j]++;
            }
        }
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (deg_in[i] != deg_out[i]) {
                if (deg_in[i] == deg_out[i] - 1) {
                    if (start == -1) {
                        start = i;
                    } else {
                        return {};
                    }
                } else if (deg_in[i] - 1 == deg_out[i]) {
                    if (end == -1) {
                        end = i;
                    } else {
                        return {};
                    }
                } else {
                    return {};
                }
            }
        }
        if (start == -1 && end == -1) {
            // pode comecar em qualquer vertice com alguma aresta (mas tem que terminar nele tambem)
            for (int i = 0; i < n; i++) {
                if (deg_out[i] > 0) {
                    start = i;
                    end = i;
                    break;
                }
            }
            assert(start != -1);
        } else if (start == -1 || end == -1) {
            return {};
        }
        function<void(int)> dfs_et = [&](int u) {
            while (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];
                dfs_et(v);
            }
            cur.push_back(u);
        };
        dfs_et(start);
        if ((int)cur.size() != m + 1) {
            return {};
        }
        reverse(cur.begin(), cur.end());
        return cur;
    }
} et_finder;

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
    et_finder.build(n);
    map<pair<int, int>, vector<int>> edge_id;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        edge_id[{u, v}].push_back(i);
    }
    if (m == 0) {
        cout << "Yes" << endl;
        cout << 0 << endl;
        cout << endl;
        return;
    }
    vector<int> path = et_finder.find();
    if (path.empty()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < m; i++) {
            cout << path[i] << " ";
        }
        cout << path[m] << endl;
        for (int i = 0; i < m; i++) {
            cout << edge_id[{path[i], path[i + 1]}].back() << " ";
            edge_id[{path[i], path[i + 1]}].pop_back();
        }
        cout << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
