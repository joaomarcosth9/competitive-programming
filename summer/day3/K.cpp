#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> ii;
int testcases = 0;
const int INF = 1.05e9;
const ll INFLL = 4.5e18;
#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#define dbarr(x...)
#endif

const int MAXN = 3e5 + 10; // Graph Size

int n, m, sn, clk, id;
int pre[MAXN], lo[MAXN], stk[MAXN], ebcc[MAXN]; // ebcc[v] is the bicconected component of v
vector<pair<int, bool>> adj[MAXN], adjbcc[MAXN];
map<ii, bool> bridge;
bool nodeHas[MAXN];

void addBridge(int u, int v) {
    if (u > v) swap(u, v);
    bridge[ii(u, v)] = true;
}

bool isBridge(int u, int v) {
    if (u > v) swap(u, v);
    return bridge.count(ii(u, v));
}

void dfs_ebcc(int v, int p) {
    lo[v] = pre[v] = clk++;
    stk[sn++] = v;

    for (auto [x, a] : adj[v]) {
        if (pre[x] == -1) {
            dfs_ebcc(x, v);
            lo[v] = min(lo[v], lo[x]);
        } else if (x != p)
            lo[v] = min(lo[v], pre[x]);
    }
    if (lo[v] == pre[v]) {
        int u;
        do {
            u = stk[--sn];
            ebcc[u] = id;
        } while (u != v);
        id++;
    }
}

int findebcc() {
    fill(pre, pre + n + 1, -1);
    sn = clk = id = 0;
    for (int v = 0; v < n; v++) // 0 indexed
        if (pre[v] == -1) dfs_ebcc(v, v);

    return id;
}

void build_ebcc_graph() { // Build ebcc condensation tree
    for (int v = 0; v < n; v++)
        for (auto [x, a] : adj[v])
            if (ebcc[v] != ebcc[x]) {
                adjbcc[ebcc[v]].push_back(ii(ebcc[x], a));
            } else if (a) {
                // same ebcc
                nodeHas[ebcc[v]] = true;
            }
}

bool res = false;

void dfs(int u, int d, int p = -1, bool found = false) {
    if (nodeHas[u]) found = true;
    if (u == d) {
        res = found;
        return;
    }
    for (auto [v, a] : adjbcc[u])
        if (v != p) {
            bool _found = found;
            if (a) _found = true;
            dfs(v, d, u, _found);
        }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        bool a;
        cin >> a;
        adj[u].push_back(ii(v, a));
        adj[v].push_back(ii(u, a));
    }
    int u, d;
    cin >> u >> d;
    u--, d--;
    findebcc();
    build_ebcc_graph();
    u = ebcc[u], d = ebcc[d];
    dfs(u, d);
    cout << (res ? "YES" : "NO") << endl;
}

signed main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (testcases) cin >> tsts;
    while (tsts--) solve();
    return 0;
}
