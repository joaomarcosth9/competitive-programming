#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#define cerr                                                                                                           \
    if (false) cerr
#endif
#define endl '\n'
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define L1(res...) [&](const auto &x) { return res; }
#define L2(res...) [&](const auto &x, const auto &y) { return res; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> i3;
#define int ll

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
int n;
ll a[maxn], res[maxn];
int COST = 0;
int sz[maxn];
// a[i] < 2^20

void dfs(int u, int p = -1) {
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    if (p != -1) {
        COST += (a[u] ^ a[p]) * sz[u];
    }
}

void dfs2(int u, int p = -1) {
    if (p != -1) {
        res[u] = res[p];
        int up = n - sz[u];
        res[u] -= sz[u] * (a[u] ^ a[p]);
        res[u] += up * (a[u] ^ a[p]);
    }
    for (int v : adj[u])
        if (v != p) {
            dfs2(v, u);
        }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    res[0] = COST;
    dfs2(0);
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC)
        cin >> TC;
    else
        TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        for (int i = 0; i < n; i++) adj[i].clear();
        for (int i = 0; i < n; i++) a[i] = res[i] = 0;
        COST = 0;
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
