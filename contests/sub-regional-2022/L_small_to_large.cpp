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

const int maxn = 1e5 + 5;
vector<ii> adj[maxn];
int n;
int a[maxn], g[maxn];
ll res[maxn];
map<int, int> f[maxn];

void dfs(int u = 0, int p = -1, int ed = -1) {
    for (auto &[v, id] : adj[u]) if (v != p) {
        dfs(v, u, id);
        if (size(f[v]) > size(f[adj[u][0].first])) {
            swap(v, adj[u][0].first);
            swap(id, adj[u][0].second);
        }
    }

    if (ed == -1) return;

    auto [v, big] = adj[u][0];
    
    if (v != p) {
        swap(f[u], f[v]);
        res[ed] = res[big];
    }

    res[ed] -= ((ll)f[u][a[u]] * (g[a[u]] - f[u][a[u]]));
    f[u][a[u]]++;
    res[ed] += ((ll)f[u][a[u]] * (g[a[u]] - f[u][a[u]]));

    for (int i = 1; i < (int)size(adj[u]); i++) {
        v = adj[u][i].first;
        if (v != p) for (auto [c, fvc] : f[v]) {
            res[ed] -= ((ll)f[u][c] * (g[c] - f[u][c]));
            f[u][c] += fvc;
            res[ed] += ((ll)f[u][c] * (g[c] - f[u][c]));
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g[a[i]]++;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v, i);
        adj[v].eb(u, i);
    }
    dfs();
    for (int i = 0; i < n - 1; i++) cout << res[i] << " ";
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
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
