#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

struct sat2 {
    int n;
    vector<vector<int>> g, gt;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    // number of variables
    sat2(int _n) {
        n = 2 * (_n + 5);
        g.assign(n, vector<int>());
        gt.assign(n, vector<int>());
    }
    void add_impl(int v, int u, bool v_sign, bool u_sign) {
        g[2 * v + v_sign].push_back(2 * u + u_sign);
        g[2 * u + !u_sign].push_back(2 * v + !v_sign);
        gt[2 * u + u_sign].push_back(2 * v + v_sign);
        gt[2 * v + !v_sign].push_back(2 * u + !u_sign);
    }
    void add_eq(int u, int v) {
        add_impl(u, v, 0, 0);
        add_impl(u, v, 1, 1);
    }
    void add_diff(int u, int v) {
        add_impl(u, v, 0, 1);
        add_impl(u, v, 1, 0);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : g[v]) {
            if (!used[u]) {
                dfs1(u);
            }
        }
        order.push_back(v);
    }
    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : gt[v]) {
            if (comp[u] == -1) {
                dfs2(u, cl);
            }
        }
    }
    bool solve() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                dfs1(i);
            }
        }

        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1) {
                dfs2(v, j++);
            }
        }

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1]) {
                return false;
            }
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }
};

void solve() {
    int n, m; cin >> n >> m;

    sat2 sat(m);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> s(n);

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int u; cin >> u;
            u--;
            s[u].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            sat.add_diff(s[i][0], s[i][1]);
        } else {
            sat.add_eq(s[i][0], s[i][1]);
        }
    }

    if (!sat.solve()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    /* cout << solve() << endl; */
    /* cout << (solve() ? "Yes" : "No") << endl; */
}
