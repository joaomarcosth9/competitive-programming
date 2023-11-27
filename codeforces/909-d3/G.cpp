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
int n, q, a[maxn], sz[maxn];
vector<int> adj[maxn];
vector<i3> qr[maxn];

void dfs_sz(int u = 0, int p = -1) {
    sz[u] = 1;
    for (int &v : adj[u]) {
        if (v != p) {
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
        }
    }
}

void dfs(int u = 0, int p = -1) {
}

void solve() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 0; i < n; i++) cin >> a[i];

    for (int j = 0; j < q; j++) {
        int l, r, u; cin >> l >> r >> u;
        l--; r--; u--;
        qr[u].emplace_back(l, r, j);
    }

    dfs_sz();

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
