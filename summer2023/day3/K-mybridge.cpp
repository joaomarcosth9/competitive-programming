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

typedef tuple<int, int, int> i3;

const int maxn = 4e5;
bool vis[maxn];
int ncc = 2, dp[maxn], pa[maxn], dep[maxn], ebcc[maxn];
vector<ii> adj[maxn], adjbcc[maxn];
vector<i3> bridges;
bool nodeHas[maxn];

void dfs_dp(int u, int p = -1, int d = 0) {
    dep[u] = d;
    pa[u] = p;
    vis[u] = true;
    for (auto [v, a] : adj[u])
        if (v != p) {
            if (vis[v]) {
                if (dep[v] < dep[u]) dp[v]--, dp[u]++;
            } else {
                dfs_dp(v, u, d + 1);
                dp[u] += dp[v];
            }
        }
}

void dfs_bcc(int u, int p = -1, int cc = 1, int _a = 0) {
    vis[u] = true;
    if (dp[u] == 0 && p != -1) {
        bridges.emplace_back(u, p, _a);
        db(bridges.back());
        cc = ncc++;
    } else if (_a) {
        nodeHas[cc] = 1;
    }
    ebcc[u] = cc;
    for (auto [v, a] : adj[u])
        if (!vis[v]) {
            dfs_bcc(v, u, cc, a);
        }
}

void find_bridges(int s) {
    dfs_dp(s);
    memset(vis, false, sizeof(vis));
    dfs_bcc(s);
    for (auto [u, v, a] : bridges) {
        adjbcc[ebcc[u]].emplace_back(ebcc[v], a);
        adjbcc[ebcc[v]].emplace_back(ebcc[u], a);
        db(u, v);
        db(ebcc[u], ebcc[v]);
        db(adjbcc[ebcc[u]].back(), adjbcc[ebcc[v]].back());
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
    int n, m;
    cin >> n >> m;
    vector<i3> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int a;
        cin >> a;
        adj[u].push_back(ii(v, a));
        adj[v].push_back(ii(u, a));
        edges.emplace_back(u, v, a);
    }
    int u, d;
    cin >> u >> d;
    find_bridges(u);
    bool db = 1;
    db(db);
    db("EBCC");
    db(ebcc[u], ebcc[d]);
    /* for(auto [uu,vv,a] : edges){ */
    /*     if(ebcc[uu] == ebcc[vv]) nodeHas[ebcc[uu]] = a; */
    /* } */
    u = ebcc[u], d = ebcc[d];
    /* for(int i = 1; i <= n; i++){ */
    /*     db(i); */
    /*     for(auto a : adjbcc[i]){ */
    /*         cout << a.first << "," << a.second << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
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
