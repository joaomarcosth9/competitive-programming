#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif
#define endl '\n'
#define int ll
using ll = long long;

const int MAX = 3e5 + 5;
vector<int> g[MAX];
int n, res, color[MAX], sz[MAX], rem[MAX];
int now[MAX], others[MAX], nxt[MAX];

int dfs_sz(int i, int l = -1) {
    sz[i] = 1;
    for (int j : g[i])
        if (j != l and !rem[j]) sz[i] += dfs_sz(j, i);
    return sz[i];
}

int centroid(int i, int l, int size) {
    for (int j : g[i])
        if (j != l and !rem[j] and sz[j] > size / 2) return centroid(j, i, size);
    return i;
}

vector<int> seen, all_seen;

void compute(int u, int l, int c) {
    if (now[color[u]] == 0 && color[u] != color[c]) {
        res += others[color[u]];
        nxt[color[u]]++;
    }
    if (color[u] == color[c] && now[color[u]] == 0) {
        res++;
    }
    seen.push_back(color[u]);
    all_seen.push_back(color[u]);
    now[color[u]]++;
    for (int v : g[u]) {
        if (v != l && !rem[v]) {
            compute(v, u, c);
        }
    }
    now[color[u]]--;
}

void decomp(int i) {
    int c = centroid(i, i, dfs_sz(i));
    rem[c] = 1;

    for (auto j : g[c]) if (!rem[j]) {

        compute(j, c, c);

        for (auto k : seen) {
            others[k] += nxt[k];
            nxt[k] = now[k] = 0;
        }

        seen.clear();
    }

    for (auto k : all_seen) {
        others[k] = 0;
        now[k] = 0;
        nxt[k] = 0;
    }
    all_seen.clear();

    for (int j : g[c])
        if (!rem[j]) decomp(j);
}

void build() {
    for (int i = 0; i < n; i++) rem[i] = 0;
    decomp(0);
}

void solve() {
    res = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> color[i];
        color[i]--;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    build();

    cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int TC; cin >> TC;
    while (TC--) {
        solve();
        for (int i = 0; i <= n + 5; i++) {
            g[i].clear();
            color[i] = sz[i] = rem[i];
            others[i] = now[i] = nxt[i] = 0;
        }
        seen.clear();
        all_seen.clear();
        res = 0;
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
    }
}
