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

// Bridges e Edge Biconnected Components
//
// Acha todas as pontes em O(n)
// Tambem constroi a arvore condensada, mantendo
// so as pontes como arestas e o resto comprimindo
// em nodos
//
// Salva no vetor bridges os pares {u, v} cujas arestas sao pontes

typedef pair<int, int> ii;
const int maxn = 2e5 + 5;
int n, m;
bool vis[maxn];
int dp[maxn], dep[maxn];
vector<int> adj[maxn];
vector<ii> bridges;

void dfs_dp(int u, int p = -1, int d = 0) {
    dp[u] = 0, dep[u] = d, vis[u] = 1;
    for (auto v : adj[u]) {
        if (v != p) {
            if (vis[v]) {
                if (dep[v] < dep[u]) dp[v]--, dp[u]++;
            } else {
                dfs_dp(v, u, d + 1);
                dp[u] += dp[v];
            }
        }
    }
    if (dp[u] == 0 && p != -1) { // edge {u, p} eh uma ponte
        bridges.emplace_back(u, p);
    }
}

void find_bridges() {
    memset(vis, 0, n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs_dp(i);
        }
    }
}

// Edge Biconnected Components (requer todo codigo acima)

int ebcc[maxn], ncc = 0;
vector<int> adjbcc[maxn];

void dfs_ebcc(int u, int p, int cc) {
    vis[u] = 1;
    if (dp[u] == 0 && p != -1) {
        cc = ++ncc;
    }
    ebcc[u] = cc;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs_ebcc(v, u, cc);
        }
    }
}

void build_ebcc_graph() {
    find_bridges();
    memset(vis, 0, n);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs_ebcc(i, -1, ncc);
            ++ncc;
        }
    }
    // Opcao 1 - constroi o grafo condensado passando por todas as edges
    for (int u = 0; u < n; u++) {
        for (auto v : adj[u]) {
            if (ebcc[u] != ebcc[v]) {
                adjbcc[ebcc[u]].emplace_back(ebcc[v]);
            } else {
                // faz algo
            }
        }
    }
    // Opcao 2 - constroi o grafo condensado passando so pelas pontes
    for (auto [u, v] : bridges) {
        adjbcc[ebcc[u]].emplace_back(ebcc[v]);
        adjbcc[ebcc[v]].emplace_back(ebcc[u]);
    }
}

void solve() {

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 0;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
