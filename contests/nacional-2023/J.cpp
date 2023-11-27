#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int blk = 100;
vector<int> adj[maxn];
int up[maxn][20];
int tin[maxn], tout[maxn], t = 0;
int d[maxn];

void dfs(int v, int p = 0) {
    up[v][0] = p;
    tin[v] = t++;
    for (int i = 1; i < 20; i++) {
        int u = up[v][i - 1];
        up[v][i] = up[u][i - 1];
    }
    for (auto u : adj[v]) {
        if (u != p) {
            d[u] = d[v] + 1;
            dfs(u, v);
        }
    }
    tout[v] = t++;
}

bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}

int lca(int v, int u) {
    if (anc(v, u)) return v;
    if (anc(u, v)) return u;
    for (int i = 19; i >= 0; i--) {
        if (!anc(up[v][i], u)) {
            v = up[v][i];
        }
    }
    return up[v][0];
}

int dist(int v, int u) {
    return d[v] + d[u] - 2 * d[lca(v, u)];
}

int main() {
    cout.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    dfs(0);
    vector<int> ans(n), dis(n, 1e9);
    iota(ans.begin(), ans.end(), 0);
    vector<int> q;
    for (int i = n - 1; i >= 0; i--) {
        if (q.size() < blk) {
            for (int j = (int)q.size() - 1; j >= 0; j--) {
                int dd = dist(q[j], i);
                if (dd < dis[i] || (dd == dis[i] && q[j] < ans[i])) {
                    dis[i] = dd;
                    ans[i] = q[j];
                }
            }
        } else {
            vector<int> now(n, 1e9), w(n, 1e9);
            for (auto u : q) now[u] = 0, w[u] = u;
            int b = q.back();
            for (int j = 0; j < (int)q.size(); j++) {
                int v = q[j];
                for (auto u : adj[v]) {
                    if (now[v] + 1 < now[u] || (now[v] + 1 == now[u] && w[v] < w[u])) {
                        if (now[u] > now[v] + 1) {
                            q.emplace_back(u);
                        }
                        now[u] = now[v] + 1;
                        w[u] = w[v];
                    }
                }
            }
            for (int j = 0; j < b; j++) {
                if (now[j] < dis[j] || (now[j] == dis[j] && w[j] < ans[j])) {
                    dis[j] = now[j];
                    ans[j] = w[j];
                }
            }
            q.clear();
        }
        q.emplace_back(i);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1  << ' ';
    }
    cout << endl;
}
