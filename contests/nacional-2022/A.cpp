#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int maxn = 1e3 + 5;
int n;
set<int> g[maxn], gi[maxn];
bool vis[maxn], vis2[maxn], vis3[maxn];
char res[maxn];

void dfs(int u) {
    vis[u] = 1;
    for (int v : gi[u]) {
        if (!vis[v]) dfs(v);
    }
}

void dfs2(int u) {
    vis2[u] = 1;
    for (int v : gi[u]) {
        if (!vis2[v]) dfs2(v);
    }
}

void dfs3(int u) {
    vis3[u] = 1;
    for (int v : gi[u]) {
        if (!vis3[v]) dfs3(v);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[i].insert(u);
        g[i].insert(v);
        gi[u].insert(i);
        gi[v].insert(i);
    }
    for (int i = 1; i <= n; i++) {
        vector<int> outs;
        for (int v : g[i]) outs.push_back(v);
        int dr = 0;
        for (int v : outs) {
            gi[v].erase(i);
        }
        dfs(i);
        dfs2(outs[0]);
        dfs3(outs[1]);
        for (int j = 1; j <= n; j++)
            if (j != i) {
                if (vis[j] && vis2[j] && vis3[j]) {
                    dr = 1;
                    break;
                }
            }
        memset(vis, 0, n + 1);
        memset(vis2, 0, n + 1);
        memset(vis3, 0, n + 1);
        res[i] = (dr ? 'Y' : 'N');
        for (int v : outs) {
            gi[v].insert(i);
        }
    }
    for (int i = 1; i <= n; i++) cout << res[i];
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else
        solve();
    return 0;
}
