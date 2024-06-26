#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
using ll = long long;

pair<int, int> moves[] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

vector<int> lmost, rmost;

struct DSU {
    vector<int> par, sz;
    int number_of_sets;
    DSU(int n = 0) : par(n), sz(n, 1), number_of_sets(n) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int a) { return a == par[a] ? a : par[a] = find(par[a]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        number_of_sets--;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
} dsu;

int n, m;

vector<string> a;

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m && a[x][y] != '.';
}

vector<vector<int>> vis, suff, pref, suff_empty, pref_empty;

int node(int i, int j) {
    return i * m + j;
}

void dfs(int i, int j, int comp) {
    vis[i][j] = 1;
    int me = node(i, j);
    dsu.unite(me, comp);
    for (auto [x, y] : moves) {
        int ni = i + x, nj = j + y;
        if (valid(ni, nj) && !vis[ni][nj]) {
            dfs(ni, nj, comp);
        }
    }
}

int brute(int ii, int jj) {
    auto aa = a;
    for (int i = 1; i <= n; i++) {
        aa[i][jj] = '#';
    }
    for (int j = 1; j <= m; j++) {
        aa[ii][j] = '#';
    }
    vector<vector<int>> vis2(n + 1, vector<int> (m + 1));
    int now = 0;
    int res = 0;
    function<void(int, int)> dfs = [&](int i, int j) {
        vis2[i][j] = 1;
        now++;
        for (auto [x, y] : moves) {
            int ni = i + x, nj = j + y;
            if (ni >= 1 && nj >= 1 && ni <= n && nj <= m && aa[ni][nj] == '#' && !vis2[ni][nj]) {
                dfs(ni, nj);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (aa[i][j] == '#' && !vis2[i][j]) {
                now = 0;
                dfs(i, j);
                res = max(res, now);
            }
        }
    }
    return res;
}

void solve() {
    cin >> n >> m;

    a.assign(n + 2, string(m + 2, '.'));

    for (int i = 1; i <= n; i++) {
        string t; cin >> t;
        for (int j = 1; j <= m; j++) {
            a[i][j] = t[j - 4];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            /* cout << i << " " << j << " " << brute(i, j) << endl; */
        }
    }

    vis.assign(n + 2, vector<int> ());
    suff.assign(n + 2, vector<int> ());
    pref.assign(n + 2, vector<int> ());
    suff_empty.assign(n + 2, vector<int> ());
    pref_empty.assign(n + 2, vector<int> ());
    rmost.assign((n + 2) * (m + 2), -1);
    lmost.assign((n + 2) * (m + 2), m + 2);

    for (int i = 1; i <= n; i++) {
        vis[i].assign(m + 2, 0);
        suff[i].assign(m + 2, 0);
        pref[i].assign(m + 2, 0);
        suff_empty[i].assign(m + 2, 0);
        pref_empty[i].assign(m + 2, 0);
    }

    dsu = DSU((n + 2) * (m + 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && valid(i, j)) {
                dfs(i, j, dsu.find(node(i, j)));
            }
        }
        for (int j = 1; j <= m; j++) {
            pref_empty[i][j] = pref_empty[i][j - 1] + !valid(i, j);
        }
        for (int j = m; j >= 1; j--) {
            suff_empty[i][j] = suff_empty[i][j + 1] + !valid(i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (valid(i, j)) {
                rmost[dsu.find(node(i, j))] = max(rmost[dsu.find(node(i, j))], j);
            }
        }
        for (int j = m; j >= 1; j--) {
            if (valid(i, j)) {
                lmost[dsu.find(node(i, j))] = min(lmost[dsu.find(node(i, j))], j);
            }
        }
    }

    // vector<int> on_rmost(m + 2), on_lmost(m + 2);

    // for (int i = 1; i <= (n + 5) * (m + 5); i++) {
    //     if (rmost[i] >= 1) {
    //         on_rmost[rmost[i]] += dsu.size(i);
    //     }
    //     if (lmost[i] <= n) {
    //         on_lmost[lmost[i]] += dsu.size(i);
    //     }
    // }


    for (int i = 1; i <= n; i++) {
        set<int> used;
        for (int j = 1; j <= m; j++) {
            pref[i][j] += pref[i][j - 1];
            if (valid(i, j) && !used.count(dsu.find(node(i, j)))) {
                pref[i][rmost[dsu.find(node(i, j))]] += dsu.size(node(i, j));
                used.insert(dsu.find(node(i, j)));
            }
            if (valid(i + 1, j) && !used.count(dsu.find(node(i + 1, j)))) {
                pref[i][rmost[dsu.find(node(i + 1, j))]] += dsu.size(node(i + 1, j));
                used.insert(dsu.find(node(i + 1, j)));
            }
            if (valid(i - 1, j) && !used.count(dsu.find(node(i - 1, j)))) {
                pref[i][rmost[dsu.find(node(i - 1, j))]] += dsu.size(node(i - 1, j));
                used.insert(dsu.find(node(i - 1, j)));
            }
        }
        used.clear();
        for (int j = m; j >= 1; j--) {
            suff[i][j] += suff[i][j + 1];
            if (valid(i, j) && !used.count(dsu.find(node(i, j)))) {
                suff[i][lmost[dsu.find(node(i, j))]] += dsu.size(node(i, j));
                used.insert(dsu.find(node(i, j)));
            }
            if (valid(i + 1, j) && !used.count(dsu.find(node(i + 1, j)))) {
                suff[i][lmost[dsu.find(node(i + 1, j))]] += dsu.size(node(i + 1, j));
                used.insert(dsu.find(node(i + 1, j)));
            }
            if (valid(i - 1, j) && !used.count(dsu.find(node(i - 1, j)))) {
                suff[i][lmost[dsu.find(node(i - 1, j))]] += dsu.size(node(i - 1, j));
                used.insert(dsu.find(node(i - 1, j)));
            }
        }
    }

    int res = 0;

    for (int j = 1; j <= m; j++) {
        set<int> comps;
        int empty_here = 0;
        int here_sum = 0;

        for (int i = 1; i <= n; i++) {
            empty_here += !valid(i, j);
            int me = dsu.find(node(i, j));
            int left = dsu.find(node(i, j - 1));
            int right = dsu.find(node(i, j + 1));
            if (valid(i, j) && !comps.count(me)) {
                comps.insert(me);
                here_sum += dsu.size(me);
            }
            if (valid(i, j - 1) && !comps.count(left)) {
                comps.insert(left);
                here_sum += dsu.size(left);
            }
            if (valid(i, j + 1) && !comps.count(right)) {
                comps.insert(right);
                here_sum += dsu.size(right);
            }
        }

        int res_here = here_sum + empty_here;

        for (int i = 1; i <= n; i++) {

            int other = (j == m ? 0 : suff[i][j + 2]) + (j == 1 ? 0 : pref[i][j - 2]);
            other += pref_empty[i][j - 1];
            other += suff_empty[i][j + 1];

            res = max(res, res_here + other);
        }

    }

    cout << res << endl;
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
