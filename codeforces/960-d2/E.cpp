#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
using ll = long long;

void solve() {
    int n;
    cin >> n;

    bool db = 0;

    const int M = 70;

    vector<vector<int>> adj(n);

    debug(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<int(int)> ask = [&] (int u) {
        cout << "? " << u + 1 << endl;
        int ans;
        cin >> ans;
        return ans;
    };

    function<void(int)> guess = [&] (int u) {
        cout << "! " << u + 1 << endl;
        db = 1;
    };

    vector<int> par(n);
    vector<bool> rem(n, false);

    function<void(int, int)> dfs_par = [&] (int u, int p) {
        par[u] = p;
        for (int v : adj[u]) if (!rem[v]) {
            if (v != p) {
                dfs_par(v, u);
            }
        }
    };
    dfs_par(0, 0);

    function<void(int)> remove = [&] (int u) {
        rem[u] = 1;
        for (int v : adj[u]) if (!rem[v]) {
            if (v != par[u]) {
                remove(v);
            }
        }
    };

    function<int(int, int)> mx_depth = [&] (int u, int d) {
        int ret = d;
        for (int v : adj[u]) if (!rem[v]) {
            if (v != par[u]) {
                ret = max(ret, mx_depth(v, d + 1));
            }
        }
        return ret;
    };

    vector<int> vet;

    function<bool(int, int, int)> get_mx_dep = [&] (int u, int d, int MAX) {
        if (d == MAX) {
            vet.push_back(u);
            return true;
        }
        for (int v : adj[u]) if (!rem[v]) {
            if (v != par[u]) {
                if (get_mx_dep(v, d + 1, MAX)) {
                    vet.push_back(u);
                    return true;
                }
            }
        }
        return false;
    };

    function<void(int)> find = [&] (int u) {
        assert(vet.empty());
        get_mx_dep(u, 1, mx_depth(u, 1));
        reverse(vet.begin(), vet.end());
        int m = (int)vet.size();
        for (int i = m - 1; i >= 0; i--) {
            int is_here = ask(vet[i]);
            if (is_here) {
                guess(vet[i]);
                if (db) return;
            // } else {
            //     int is_on_u = ask(u);
            //     if (!is_on_u) {
            //         guess(par[par[u]]);
            //         if (db) return;
            //     }
            }
        }
        if (u == 0 || par[vet[0]] == 0) {
            guess(0);
            if (db) return;
        }
        // i know the mole is in the path [0, par[vet[0])
        vector<int> path;
        int v = par[vet[0]];
        while (v != 0) {
            path.push_back(v);
            v = par[v];
        }
        path.push_back(0);
        int l = 0, r = (int)path.size() - 1;
        while (r - l > 1) {
            int mid = (l + r + 1) / 2;
            int v = path[mid];
            int is = ask(v);
            if (is == 1) {
                r = mid;
            } else {
                l = mid + 1;
                r = min(r + 1, (int)path.size() - 1);
            }
        }
        r = min(r, (int)path.size() - 1);
        l = min(l, (int)path.size() - 1);
        l = max(l, 0);
        r = max(r, 0);
        for (int i = r; i >= l; i--) {
            int is = ask(path[i]);
            if (!is) {
                guess(par[par[path[i]]]);
                break;
            }
        }
        if (!db) guess(0);
    };

    function<int(int, int)> dfs = [&] (int u, int p) {
        int d = 1;
        for (int v : adj[u]) if (!rem[v]) {
            if (db) return 0;
            if (v != p) {
                d = max(d, 1 + dfs(v, u));
                if (db) return 0;
            }
        }
        if (u == 0) {
            // da pra achar
            find(0);
            assert(db);
            if (db) return 0;
        } else if (d == M) {
            if (db) return 0;
            int is_here = ask(u);
            if (is_here) {
                // da pra achar
                find(u);
                assert(db);
                if (db) return 0;
            }
            remove(u);
            return 0;
        }
        if (db) return 0;

        return d;
    };

    dfs(0, 0);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    // cout << solve() << endl;
    // cout << (solve() ? "Yes" : "No") << endl;
}
