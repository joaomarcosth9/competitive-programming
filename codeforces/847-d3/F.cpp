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

int n, c0;
const int maxn = 2e5 + 5;

vector<int> adj[maxn], dist[maxn];
int sz[maxn], rem[maxn], p[maxn];

int dfs_sz(int i, int l = -1) {
    sz[i] = 1;
    for (int j : adj[i])
        if (j != l and !rem[j]) sz[i] += dfs_sz(j, i);
    return sz[i];
}

int centroid(int i, int l, int size) {
    for (int j : adj[i])
        if (j != l and !rem[j] and sz[j] > size / 2) return centroid(j, i, size);
    return i;
}

void dfs_dist(int i, int l, int d = 0) {
    dist[i].push_back(d);
    for (int j : adj[i])
        if (j != l and !rem[j]) dfs_dist(j, i, d + 1);
}

void decomp(int i, int l = -1) {
    int c = centroid(i, i, dfs_sz(i));
    rem[c] = 1, p[c] = l;
    dfs_dist(c, c);
    for (int j : adj[c])
        if (!rem[j]) decomp(j, c);
}

void build() {
    for (int i = 0; i < n; i++) rem[i] = 0, dist[i].clear();
    decomp(0);
    for (int i = 0; i < n; i++) reverse(dist[i].begin(), dist[i].end());
}

int dp[maxn];

void solve() {

    cin >> n >> c0;
    c0--;

    for (int i = 0; i < n; i++) {
        sz[i] = rem[i] = p[i] = 0;
        dp[i] = 1e9;
        adj[i].clear();
        dist[i].clear();
    }

    int res = 1e9;

    auto update = [&] (int u) {
        int v = u, it = 0;
        while (v != -1) {
            res = min(res, dp[v] + dist[u][it]);
            v = p[v];
            it++;
        }
        v = u, it = 0;
        while (v != -1) {
            dp[v] = min(dp[v], dist[u][it]);
            v = p[v];
            it++;
        }
    };

    vector<int> op(n - 1);

    for (int i = 0; i < n - 1; i++) cin >> op[i];
    for (int i = 0; i < n - 1; i++) op[i]--;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    build();

    update(c0);

    for (int i = 0; i < n - 1; i++) {
        int u = op[i];
        update(u);
        cout << res << " ";
    }
    cout << endl;

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
        /* cout << solve() << endl; */
        /* cout << (solve() ? "Yes" : "No") << endl; */
        TEST += 1;
    }
}
