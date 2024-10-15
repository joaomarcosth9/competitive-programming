#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool bip = 1;
    vector<int> c(n + 1, 0);
    function<void(int, int)> dfs = [&] (int u, int cnow) {
        c[u] = cnow;
        for (int v : adj[u]) {
            if (c[v] == 0) {
                dfs(v, cnow ^ 3);
            } else if (c[v] == c[u]) {
                bip = 0;
            }
        }
    };
    dfs(1, 1);
    if (!bip) {
        // Alice
        cout << "Alice" << endl;
        c = vector<int>(n + 1, 0);
        for (int round = 1; round <= n; round++) {
            cout << "1 2" << endl;
            int u, co; cin >> u >> co;
            c[u] = co;
        }
    } else {
        // Bob
        cout << "Bob" << endl;

        vector<bool> cl(3, 0);
        vector<bool> cr(3, 0);

        vector<int> nodes_l, nodes_r;

        for (int i = 1; i <= n; i++) {
            if (c[i] == 1) {
                nodes_l.push_back(i);
            } else if (c[i] == 2) {
                nodes_r.push_back(i);
            } else {
                assert(0);
            }
        }

        int c1, c2; cin >> c1 >> c2;

        cl[c1] = 1;
        cr[c2] = 1;

        int oc1 = c1, oc2 = c2;
        int c3 = c1 ^ c2;

        int itl = 0, itr = 0;

        cout << nodes_l[itl++] << " " << c1 << endl;
        int ptr = 1;

        if (ptr < n && itl == (int)nodes_l.size()) {
            cl[c1] = 0;
            cr[c3] = 1;
        }

        for (int round = 2; round <= n; round++) {
            cin >> c1 >> c2;
            if (cl[c1]) {
                cout << nodes_l[itl++] << " " << c1 << endl;
                ptr++;
                if (ptr < n && itl == (int)nodes_l.size()) {
                    cl[c1] = 0;
                    cr[c3] = 1;
                }
            } else if (cl[c2]) {
                cout << nodes_l[itl++] << " " << c2 << endl;
                ptr++;
                if (ptr < n && itl == (int)nodes_l.size()) {
                    cl[c2] = 0;
                    cr[c3] = 1;
                }
            } else if (cr[c1]) {
                cout << nodes_r[itr++] << " " << c1 << endl;
                ptr++;
                if (ptr < n && itr == (int)nodes_r.size()) {
                    cr[c1] = 0;
                    cl[c3] = 1;
                }
            } else if (cr[c2]) {
                cout << nodes_r[itr++] << " " << c2 << endl;
                ptr++;
                if (ptr < n && itr == (int)nodes_r.size()) {
                    cr[c2] = 0;
                    cl[c3] = 1;
                }
            } else if (cl[c3]) {
                cout << nodes_l[itl++] << " " << c3 << endl;
                ptr++;
            } else if (cr[c3]) {
                cout << nodes_r[itr++] << " " << c3 << endl;
                ptr++;
            } else {
                assert(0);
            }
        }

        assert(ptr == n);
    }
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
