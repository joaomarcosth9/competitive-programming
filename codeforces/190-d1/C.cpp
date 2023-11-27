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

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
bool rem[maxn];
int par[maxn];
int n, sz[maxn];

void dfs(int u, int p = -1) {
    sz[u] = 1;
    for (int v : adj[u]) if (v != p && !rem[v]) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int ssz, int p = -1) {
    for (int v : adj[u]) if (!rem[v] && v != p) {
        if (sz[v] > ssz / 2) return centroid(v, ssz, u);
    }
    return u;
}

void centroid_decomp() {
    vector<int> centroids;
    dfs(0);
    auto u = centroid(0, n);
    centroids.eb(u);
    par[u] = -1;
    rem[u] = 1;
    for (int i = 0; i < (int)centroids.size(); i++) {
        u = centroids[i];
        debug(i, centroids[i]);
        for (auto v : adj[u]) if (!rem[v]) {
            debug(v);
            dfs(v);
            auto w = centroid(v, sz[v]);
            centroids.eb(w);
            par[w] = u;
            rem[w] = 1;
        }
    }
}

int Rank(int u) {
    if (par[u] == -1) return 0;
    return Rank(par[u]) + 1;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    centroid_decomp();
    for (int i = 0; i < n; i++) {
        cout << char('A' + Rank(i)) << " ";
    }
    cout << endl;
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
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
