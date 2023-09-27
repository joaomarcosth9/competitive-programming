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

const int maxn = 1e5 + 5;
vector<int> adj[maxn];
ll dp[maxn], dp2[maxn];
ll n, mod;
ll exc[maxn];
vector<ll> suff[maxn], pref[maxn];

void dfs(int u, int p = -1) {
    for (int &v : adj[u])
        if (v == p) swap(v, adj[u][0]);
    if (u != 0) adj[u].erase(begin(adj[u]));

    dp[u] = 1;
    int N = size(adj[u]);
    pref[u].assign(N, 1);
    suff[u].assign(N, 1);

    for (int v : adj[u]) dfs(v, u);

    for (int i = 0; i < N; i++) {
        if (i > 0) pref[u][i] = pref[u][i - 1];
        pref[u][i] = pref[u][i] * (dp[adj[u][i]] + 1) % mod;
    }

    for (int i = N - 1; i >= 0; i--) {
        if (i < N - 1) suff[u][i] = suff[u][i + 1];
        suff[u][i] = suff[u][i] * (dp[adj[u][i]] + 1) % mod;
    }

    for (int i = 0; i < N; i++) {
        int v = adj[u][i];
        exc[v] = 1;
        if (i > 0) exc[v] = (exc[v] * pref[u][i - 1]) % mod;
        if (i < N - 1) exc[v] = (exc[v] * suff[u][i + 1]) % mod;
    }

    if (N) dp[u] = (dp[u] * pref[u][N - 1]) % mod;
}

void dfs2(int u) {
    debug(u, dp2[u], exc[u], pref[u]);
    if (u != 0) {

        int N = size(adj[u]);
        dp2[u] = 1;
        dp2[u] = (dp2[u] * (exc[u] + 1)) % mod;
        for (int j = 0; j < N; j++) exc[adj[u][j]] = (exc[adj[u][j]] * (exc[u] + 1)) % mod;

        if (N) dp2[u] = (dp2[u] * pref[u][N - 1]) % mod;

    } else
        dp2[u] = dp[u];

    for (int v : adj[u]) {
        dfs2(v);
    }
}

void solve() {
    cin >> n >> mod;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    dfs(0);
    dfs2(0);
    for (int i = 0; i < n; i++) {
        cout << dp2[i] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 0;
    if (TC)
        cin >> TC;
    else
        TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        solve();
        /* cout << solve() << endl; */
        /* cout << (solve() ? "YES" : "NO") << endl; */
        TEST += 1;
    }
}
