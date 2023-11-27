#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto& x){ return res; }
#define L2(res...) [&](const auto& x, const auto& y){ return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int INF = 1e9 + 9;

const int maxn = 3e5 + 5, LG = 20;
int n;
int marked[maxn];

vector<int> adj[maxn];

struct BinaryLifting {
    vector<vector<int>> up;
    vector<int> tin, tout, dep;
    int CLG = 0;
    int N, t;

    const int neutral = 0;
    int merge(int l, int r) { return l + r; }

    void build(int u, int p, int d) {
        tin[u] = t++;
        dep[u] = d;
        for (int i = 0; i < CLG - 1; i++) {
            up[u][i + 1] = up[up[u][i]][i];
        }
        for (int v : adj[u])
            if (v != p) {
                up[v][0] = u;
                build(v, u, d + 1);
            }
        tout[u] = t++;
    }

    void build(int n2) {
        t = 1;
        N = n2;
        CLG = ceil(log2(N)) + 2;
        up.assign(N + 1, vector<int>(CLG));
        tin.assign(N + 1, 0);
        tout.assign(N + 1, 0);
        dep.assign(N + 1, 0);
        build(0, -1, 0);
    }

    bool ancestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

    int lca(int u, int v) {
        if (ancestor(u, v)) return u;
        if (ancestor(v, u)) return v;
        for (int i = CLG - 1; i >= 0; i--) {
            if (!ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    int kth(int u, int k) {
        for (int i = 0; i < CLG; i++) {
            if (k & (1 << i)) {
                u = up[u][i];
            }
        }
        return u;
    }
} bl;

int dis(int u, int v) {
    return bl.dep[u] + bl.dep[v] - 2 * bl.dep[bl.lca(u, v)];
}

int solve() {
    cin >> n;
    int k; cin >> k;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        marked[i] = 0;
    }
    for (int i = 0; i < k; i++) {
        int u; cin >> u; u--;
        marked[u] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    if (k == 0) return 0;

    bl.build(n);

    int res = INT_MAX;

    int nodo1 = -1, mx = -1;

    for (int i = 0; i < n; i++) {
        if (!marked[i]) continue;
        queue<int> q;
        vector<int> dist(n, INF);
        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            if (marked[u]) {
                if (dist[u] > mx) {
                    mx = dist[u];
                    nodo1 = u;
                }
            }
            q.pop();
            for (int v : adj[u]) {
                if (dist[v] <= dist[u] + 1) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        
        break;
    }

    queue<int> q;
    vector<int> dist(n, INF);

    dist[nodo1] = 0;
    mx = -1;
    int nodo2 = -1;
    q.push(nodo1);

    while (!q.empty()) {
        int u = q.front();
        if (marked[u]) {
            if (dist[u] > mx) {
                mx = dist[u];
                nodo2 = u;
            }
        }
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] <= dist[u] + 1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    for (int i = 0; i < n; i++) {
        res = min(res, max(dis(i, nodo1), dis(i, nodo2)));
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        cout << solve() << endl;
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
