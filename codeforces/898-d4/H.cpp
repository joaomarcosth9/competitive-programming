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
void out(bool ans) { cout << (ans ? "YES" : "NO") << endl; }

const int maxn = 2e5 + 5;
int n;
int a, b;
vector<int> adj[maxn];
int g[maxn];
bool vis[maxn];

bool solve() {
    cin >> n;
    cin >> a >> b;
    a--; b--;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        g[i] = 0;
        vis[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
        g[u] += 1;
        g[v] += 1;
    }
    if (a == b) {
        return false;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (g[i] == 1) {
            q.emplace(i);
        }
    }
    while (!q.empty()) {
        auto u = q.front();
        vis[u] = 1;
        q.pop();
        for (int v : adj[u]) if (!vis[v]) {
            g[v] -= 1;
            if (g[v] == 1) {
                q.emplace(v);
            }
        }
    }
    if (!vis[b]) {
        return true;
    }
    swap(a, b);
    q.emplace(a);
    vector<int> dis(n, 2e9);
    dis[a] = 0;
    int da = -1, node = -1;
    while (!q.empty()) {
        auto u = q.front();
        if (!vis[u]) {
            da = dis[u];
            node = u;
            break;
        }
        q.pop();
        for (int v : adj[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.emplace(v);
            }
        }
    }
    while (q.size()) q.pop();
    dis = vector<int>(n, 2e9);
    q.emplace(b);
    dis[b] = 0;
    int db = -1;
    while (!q.empty()) {
        auto u = q.front();
        if (u == node) {
            db = dis[u];
            break;
        }
        q.pop();
        for (int v : adj[u]) {
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.emplace(v);
            }
        }
    }
    return (da < db);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) { cin >> TC;
        int TEST = 1;
        while (TEST <= TC) {
            cerr << "[Testcase " << TEST << "]" << endl;
            /* solve(); */
            /* cout << solve() << endl; */
            cout << (solve() ? "YES" : "NO") << endl;
            ++TEST;
        }
    } else solve();
}
