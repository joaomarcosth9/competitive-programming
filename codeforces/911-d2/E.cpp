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
#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;

const int maxn = 3e5 + 5;
const int MAX = maxn;
int n, m;
ll a[maxn];

// Kosaraju
//
// O(n + m)

vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
set<int> adj[MAX]; // novo grafo
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

void dfs(int k) {
    vis[k] = 1;
    for (int i = 0; i < (int)g[k].size(); i++)
        if (!vis[g[k][i]]) dfs(g[k][i]);

    S.push(k);
}

void scc(int k, int c) {
    vis[k] = 1;
    comp[k] = c;
    for (int i = 0; i < (int)gi[k].size(); i++)
        if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju() {
    for (int i = 0; i < n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i);

    for (int i = 0; i < n; i++) vis[i] = 0;
    while (S.size()) {
        int u = S.top();
        S.pop();
        if (!vis[u]) scc(u, u);
    }
}

ll sum[MAX], nodes[MAX];
pair<ll, ll> dp[MAX];

vector<int> toposort;

void topo(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (!vis[v]) topo(v);
    }
    toposort.emplace_back(u);
}

void solve() {
    while (S.size()) S.pop();

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<set<int>> has(n);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (u == v || has[u].count(v)) continue;
        has[u].emplace(v);
        g[u].emplace_back(v);
        gi[v].emplace_back(u);
    }

    kosaraju();

    for (int i = 0; i < n; i++) sum[comp[i]] += a[i];
    for (int i = 0; i < n; i++) nodes[comp[i]]++;
    vector<int> degin(n);

    for (int u = 0; u < n; u++) {
        for (auto v : g[u]) {
            if (comp[v] != comp[u]) {
                adj[comp[u]].emplace(comp[v]);
                degin[comp[v]]++;
            }
        }
    }

    toposort.clear();

    for (int i = 0; i < n; i++) vis[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i] && degin[i] == 0) {
            topo(i);
        }
    }

    debug(toposort);

    for (int i = 0; i < (int)toposort.size(); i++) {
        int u = toposort[i];
        dp[u] = {sum[u], nodes[u]};
        debug(u, sum[u], nodes[u]);
        for (auto v : adj[u]) {
            debug(v, dp[v]);
            auto [s, N] = dp[v];
            if (N + nodes[u] > dp[u].second) {
                dp[u] = {s + sum[u], N + nodes[u]};
            } else if (N + nodes[u] == dp[u].second) {
                dp[u].first = min(dp[u].first, s + sum[u]);
            }
        }
        debug(dp[u]);
    }

    pair<ll, ll> ans = {0, 0};

    for (int i = 0; i < n; i++) {
        auto [s, N] = dp[i];
        debug(i, dp[i]);
        if (N > ans.second) {
            ans = {s, N};
        } else if (N == ans.second) {
            ans.first = min(ans.first, s);
        }
    }

    cout << ans.second << " " << ans.first << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        for (int i = 0; i <= n; i++) {
            g[i].clear();
            gi[i].clear();
            a[i] = 0;
            sum[i] = 0;
            nodes[i] = 0;
            adj[i].clear();
            dp[i] = {0, 0};
            comp[i] = vis[i] = 0;
        }
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
