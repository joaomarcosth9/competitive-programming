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
int n, m;
vector<int> adj[maxn];
int gg[maxn];
int token[maxn], bonus[maxn];
bool reach[maxn], vis[maxn];

void bfs() {
    vis[0] = 1;
    reach[0] = 1;
    queue<int> q;
    q.emplace(0);
    while (q.size()) {
        auto u = q.front();
        q.pop();
        vis[u] = reach[u] = 1;
        for (auto v : adj[u]) if (bonus[v]) {
            if (!vis[v]) q.emplace(v);
        }
    }
}

bool solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        adj[i].clear();
        gg[i] = token[i] = bonus[i] = reach[i] = vis[i] = 0;
    }

    int t, b; cin >> t >> b;
    debug(t, b);

    for (int i = 0; i < t; i++) {
        int u; cin >> u; u--;
        token[u] = 1;
        debug(u, token[u]);
    }
    for (int i = 0; i < b; i++) {
        int u; cin >> u; u--;
        bonus[u] = 1;
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    if (token[0]) return 1;

    for (int i = 0; i < n; i++) if (token[i]) {
        for (auto v : adj[i]) if (v == 0) return 1;
    }

    if (t == 1) return 0;

    bfs();

    for (int i = 0; i < n; i++) if (bonus[i]) {
        for (auto v : adj[i]) if (bonus[v]) gg[i] = gg[v] = 1;
    }

    set<int> can;
    set<int> ggs;

    for (int i = 0; i < n; i++) if (token[i]) {
        bool db = reach[i];
        for (auto v : adj[i]) if (reach[v]) db = 1;
        if (db) can.emplace(i);
    }

    for (int i = 0; i < n; i++) if (token[i]) {
        bool db = gg[i];
        for (auto v : adj[i]) if (gg[v]) db = 1;
        if (db) ggs.emplace(i);
    }

    debug(can);
    debug(ggs);

    for (auto u : can) {
        bool er = 0;
        if (ggs.count(u)) {
            er = 1; ggs.erase(u);
        }
        if (ggs.size()) return 1;
        if (er) ggs.emplace(u);
    }

    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) cin >> TC;
    else TC += 1;
    int TEST = 1;
    while (TEST <= TC) {
        cerr << "[Testcase " << TEST << "]" << endl;
        /* solve(); */
        /* cout << solve() << endl; */
        cout << (solve() ? "YES" : "NO") << endl;
        TEST += 1;
    }
}
