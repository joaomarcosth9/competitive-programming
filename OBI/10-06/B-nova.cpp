#include <bits/stdc++.h>

using namespace std;

const int MAX = 505;
int age[MAX];
int pos[MAX];
int where[MAX];
vector<int> rAdj[MAX], Adj[MAX];
int st, n, m, q, res;

void change(int u, int v) {
    int old_u = where[u], old_v = where[v];
    swap(res[u], res[v]);
    swap(where[u], where[v]);
    pos[where[u]] = u;
    pos[where[v]] = v;
}

int dfs(int u) {
    if (rAdj[u].empty()) return age[u];
    int minn = INT_MAX;
    for (auto v : rAdj[where[u]]) {
        minn = min(minn, dfs(pos[v]));
    }
    return res[u] = min(age[u], minn);
}

void dfs2(int u) {
    if (u != st) {
        if (res[u] < age[st]) return;
        res[u] = min(res[u], age[st]);
    }
    for (auto v : Adj[where[u]]) {
        dfs2(pos[v]);
    }
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        res[i] = INT_MAX;
        where[i] = pos[i] = i;
        cin >> age[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        rAdj[v].push_back(u);
    }
    while (q--) {
        char t;
        cin >> t;
        if (t == 'T') {
            int u, v;
            cin >> u >> v;
            change(u, v);
            dfs2(u), dfs2(v);
        } else {
            int u;
            cin >> u;
            cout << res[u] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
